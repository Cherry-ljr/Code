// ��㼶��֯��Ϣ�洢�ṹ.cpp: �������̨Ӧ�ó������ڵ㡣
//

#include <vector>	
#include<iostream>
#include<string>

#include <iostream>

#include <fstream>
#include "cJSON.h"

//#include"���ݻ�ȡ.h"

using namespace std;


struct Attribute {
	string key;
	string value;

	Attribute(string key, string value) {
		this->key = key;
		this->value = value;
	}
};

typedef struct TrieNode {
	string level_name;//��ǰ�㼶������
	vector<TrieNode *> childNode;//��һ����ĵ�ַ

	//���Լ���
	vector<Attribute>attribute;

	TrieNode(string name) {
		level_name = name;
	}

	//��������
	void addProperty(string key, string value) {
		Attribute at = Attribute(key, value);
		attribute.push_back(at);
	}
	//ɾ������
	void deleteProperty(string key) {
		//TODO:��key��value�а���ɾ��
		vector<Attribute>::iterator itr = attribute.begin();
		while (itr != attribute.end())
		{
			if (key == (*itr).key)
			{
				itr = attribute.erase(itr);

			}
			else
			{
				++itr;
			}
		}
	}
	//��������ֵ
	string findProperty(string key) {
		//ͨ��key������Ӧ��value
		vector<Attribute>::iterator itr = attribute.begin();
		while (itr != attribute.end())
		{
			if (key == (*itr).key)
			{
				return (*itr).value;
			}
			else
			{
				++itr;
			}
		}
	}

	//�ı�����ֵ
	void changeProperty(string key, string value) {
		//��key�е�value�޸ĳ���value
		vector<Attribute>::iterator itr = attribute.begin();
		while (itr != attribute.end())
		{
			if (key == (*itr).key)
			{
				(*itr).value = value;
				return;
			}
			else
			{
				++itr;
			}
		}
	}


	//�����ӽ��
	void addNextTier(TrieNode *node) {

		TrieNode *tNode = NULL;
		tNode = findTier(node->level_name);
		if (tNode != NULL){//���Ѵ���
			//cout << "bbbb";
			return;
		}
		else  childNode.push_back(node);
	}

	//ɾ�����
	void deleteSpace(TrieNode *TN) {

		vector<TrieNode *>::iterator itr = TN->childNode.begin();
		while (itr != TN->childNode.end())
		{
			deleteSpace(*itr);
			cout << (*itr)->level_name << endl;//��ʾɾ��������
			delete(*itr);
			++itr;
		}
	}

	void deleteNode(string name) {
		//TODO:��vector v�а���ɾ����ע���ͷſռ�
		vector<TrieNode*>::iterator it = childNode.begin();
		while (it != childNode.end()) {
			if ((*it)->level_name != name) {
				it++;
			}

			else {
				cout << "ɾ����" << (*it)->level_name << endl;

				deleteSpace(*it);//�ͷź���Ŀռ�
				delete(*it);
				it = childNode.erase(it);
			}
		}

	}

	//�����ӽ��
	TrieNode* findTier(string name) {

		//TODO:��vector v�а�����ѯ
		vector<TrieNode*>::iterator it = childNode.begin();
		while (it != childNode.end()) {
			if ((*it)->level_name != name) {
				it++;
			}
			else {
				return *it;
			}
		}
		return 0;
	}

	void outputProperty() {
		cout << level_name << " ";
		if (attribute.size() != 0) {
			cout << "���ԣ�";
			for (vector<Attribute>::const_iterator iter = attribute.cbegin(); iter != attribute.cend(); iter++)
			{
				cout << (*iter).key << "-" << (*iter).value << " ";
			}
		}
		cout << endl;
	}

}Trie;

//�½���Ա
TrieNode* newStudent(string university, string college, string major, string _class, string name, string no, string sex) {
	TrieNode *student = new TrieNode(name);
	student->addProperty("ѧУ", university);
	student->addProperty("ѧԺ", college);
	student->addProperty("רҵ", major);
	student->addProperty("�༶", _class);
	student->addProperty("ѧ��", no);
	student->addProperty("�Ա�", sex);
	return student;
}

//����Ա��������
void addStudent(TrieNode*root, string college, string major, string _class, TrieNode*student) {
	TrieNode *College;
	TrieNode *Major;
	TrieNode *__class;
	if (root->findTier(college))
		College = root->findTier(college);
	else {
		College = new TrieNode(college);
		root->addNextTier(College);
	}

	if (College->findTier(major))
		Major = College->findTier(major);
	else {
		Major = new TrieNode(major);
		College->addNextTier(Major);
	}

	if (Major->findTier(_class))
		__class = Major->findTier(_class);
	else {
		__class = new TrieNode(_class);
		Major->addNextTier(__class);
	}

	__class->addNextTier(student);
}


//������Ա
void  findStudent(TrieNode *node, string name, string no, TrieNode * &student) {
	vector<TrieNode *>::iterator itr = node->childNode.begin();

	if (node != NULL &&node->level_name == name&&node->findProperty("ѧ��") == no) {
		student = node;
		return;
	}
	while (itr != node->childNode.end())
	{
		findStudent(*itr, name, no, student);

		++itr;
	}
}


//ɾ��ѧ��

void deldeteStudent(TrieNode *root, string name, string no) {
	TrieNode*student = NULL;
	findStudent(root, name, no, student);

	if (student != NULL) {
		root->findTier(student->findProperty("ѧԺ"))->findTier(student->findProperty("רҵ"))
			->findTier(student->findProperty("�༶"))->deleteNode(name);//deleteNode�����ͷſռ�Ĳ���
	}
	else cout << "û�и�ѧ����" << endl;

}



void output(TrieNode *node) {
	node->outputProperty();

	vector<TrieNode *>::iterator itr = node->childNode.begin();
	while (itr != node->childNode.end())
	{
		output(*itr);
		++itr;
	}
}


// ����json��ʽ
void Json_Analysis(const char* text, vector<TrieNode *>&students) {
	cJSON *json, *json_name, *json_university, *json_college, *json_major, *json_class,
		*json_no, *json_sex;

	json = cJSON_Parse(text); //������json��ʽ,ʹ�øú�����ͨ��malloc()�������ڴ��п���һ���ռ䣬ʹ�������Ҫ�ֶ��ͷš�
	json_name = cJSON_GetObjectItem(json, "name");  //��ȡ��ֵ����
	json_university = cJSON_GetObjectItem(json, "university");
	json_college = cJSON_GetObjectItem(json, "college");
	json_major = cJSON_GetObjectItem(json, "major");
	json_class = cJSON_GetObjectItem(json, "class");
	json_no = cJSON_GetObjectItem(json, "no");
	json_sex = cJSON_GetObjectItem(json, "sex");


	TrieNode *student = new TrieNode(json_name->valuestring);	//��CJSON��ʽת��Ϊchar *
	student->addProperty("ѧУ", json_university->valuestring);
	student->addProperty("ѧԺ", json_college->valuestring);
	student->addProperty("רҵ", json_major->valuestring);
	student->addProperty("�༶", json_class->valuestring);
	student->addProperty("ѧ��", json_no->valuestring);
	student->addProperty("�Ա�", json_sex->valuestring);

	students.push_back(student);

	cJSON_Delete(json);  //�ͷ��ڴ� 

}

// ���ļ��ж�ȡjson��ʽ�����ݣ�����һ�����ĸ��ڵ�
TrieNode* Read_Json_Data() {

	vector<TrieNode *>students;

	//fstream  in("E:\\data.json");
	fstream  in("E:\\info.json");
	string line;

	if (in.fail())
	{
		cout << "open file error" << endl;
		return NULL;
	}
	while (getline(in, line))
	{
		Json_Analysis(line.c_str(), students);//const char *
	}

	in.close();

	//����
	vector<TrieNode*>::iterator it = students.begin();
	//�Ƚ���һ�����ڵ�

	TrieNode* Root = new TrieNode((*it)->attribute[0].value);

	while (it != students.end()) {
		TrieNode* test = Root;
		//���ڶ�ȡ��ѧ��ʱ����ѧԺ��רҵ�����Դ�����������vector�У�vector���±�1��2��3�ֱ��ӦѧԺ��רҵ���༶
		for (int i = 1; i < 4; i++) {

			if (test->findTier((*it)->attribute[i].value)) {//����ý���������Ѿ�����
			}
			else {
				TrieNode* t = new TrieNode((*it)->attribute[i].value);
				test->addNextTier(t);
			}
			test = test->findTier((*it)->attribute[i].value);

		}
		test->addNextTier(*it);//��ѧ�����ӽ���
		it++;
	}
	return Root;
}


void findPeople(TrieNode * root, vector<TrieNode *>&students) {
	//�����������������ѧ�����
	vector<TrieNode *>::iterator itr = root->childNode.begin();

	if (root != NULL && root->childNode.size() == 0) {
		students.push_back(root);
	}
	while (itr != root->childNode.end())
	{

		findPeople(*itr, students);
		++itr;
	}
}

// �����ݱ���Ϊjson��ʽ
void Save_To_Json(TrieNode * root) {
	vector<TrieNode *>students;
	findPeople(root, students);

	ofstream fout;
	fout.open("E:\\test.json");


	vector<TrieNode *>::iterator itr = students.begin();
	while (itr != students.end())
	{
		//ʹ���ַ���ƴ�ӵķ�ʽ���json��ʽ
		/*string s = "\{\"name\":\""+(*itr)->level_name+ "\"\,"+"\"university\":\""+ (*itr)->attribute[0].value + "\"\," + "\"college\":\"" + (*itr)->attribute[1].value
		+ "\"\," + "\"major\":\"" + (*itr)->attribute[2].value + "\"\," + "\"class\":\"" + (*itr)->attribute[3].value + "\"\," + "\"no\":\"" + (*itr)->attribute[4].value
		+ "\"\," + "\"sex\":\"" + (*itr)->attribute[5].value+"\"\}";*/


		cJSON * usr;
		usr = cJSON_CreateObject();   //���������ݶ���
		cJSON_AddStringToObject(usr, "name", (*itr)->level_name.c_str());  //�����ֵ�����ַ���
		cJSON_AddStringToObject(usr, "university", (*itr)->attribute[0].value.c_str());
		cJSON_AddStringToObject(usr, "college", (*itr)->attribute[1].value.c_str());
		cJSON_AddStringToObject(usr, "major", (*itr)->attribute[2].value.c_str());
		cJSON_AddStringToObject(usr, "class", (*itr)->attribute[3].value.c_str());
		cJSON_AddStringToObject(usr, "no", (*itr)->attribute[4].value.c_str());
		cJSON_AddStringToObject(usr, "sex", (*itr)->attribute[5].value.c_str());
		string s1 = cJSON_Print(usr);   //��json��ʽ��ӡ�������ַ�����ʽ
		string s;

		//ȥ��CJSON���ɵ��ַ����е� �س����Ʊ��
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != '\n'&&s1[i] != '\t')
				s += s1[i];
		}
		fout << s << endl;
		++itr;
	}
	fout.close();
}


int main()
{
	//get(500);

	TrieNode *GuiDa = Read_Json_Data();
	//output(GuiDa);

	GuiDa->deleteNode("�������ѧ�뼼��ѧԺ"); 


	TrieNode *LvKou = newStudent("���ݴ�ѧ", "��ͳѧԺ", "ͳ��", "ͳ��161", "����", "1600170075", "��");
	addStudent(GuiDa, "��ͳѧԺ", "ͳ��", "ͳ��161", LvKou);

	TrieNode *student;
	findStudent(GuiDa, "����", "1600170075", student);
	//cout << student->level_name << endl;

	//deldeteStudent(GuiDa, "�ŷ�ʢ", "1600170086");

	
	//output(GuiDa);
	//Save_To_Json(GuiDa);


	system("pause");
	return 0;
}

