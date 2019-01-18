// 多层级组织信息存储结构.cpp: 定义控制台应用程序的入口点。
//

#include <vector>	
#include<iostream>
#include<string>

#include <iostream>

#include <fstream>
#include "cJSON.h"

//#include"数据获取.h"

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
	string level_name;//当前层级的名字
	vector<TrieNode *> childNode;//下一层结点的地址

	//属性集合
	vector<Attribute>attribute;

	TrieNode(string name) {
		level_name = name;
	}

	//增加属性
	void addProperty(string key, string value) {
		Attribute at = Attribute(key, value);
		attribute.push_back(at);
	}
	//删除属性
	void deleteProperty(string key) {
		//TODO:在key，value中按名删除
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
	//查找属性值
	string findProperty(string key) {
		//通过key查找相应的value
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

	//改变属性值
	void changeProperty(string key, string value) {
		//将key中的value修改成新value
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


	//增加子结点
	void addNextTier(TrieNode *node) {

		TrieNode *tNode = NULL;
		tNode = findTier(node->level_name);
		if (tNode != NULL){//若已存在
			//cout << "bbbb";
			return;
		}
		else  childNode.push_back(node);
	}

	//删除结点
	void deleteSpace(TrieNode *TN) {

		vector<TrieNode *>::iterator itr = TN->childNode.begin();
		while (itr != TN->childNode.end())
		{
			deleteSpace(*itr);
			cout << (*itr)->level_name << endl;//显示删除的内容
			delete(*itr);
			++itr;
		}
	}

	void deleteNode(string name) {
		//TODO:在vector v中按名删除，注意释放空间
		vector<TrieNode*>::iterator it = childNode.begin();
		while (it != childNode.end()) {
			if ((*it)->level_name != name) {
				it++;
			}

			else {
				cout << "删除：" << (*it)->level_name << endl;

				deleteSpace(*it);//释放后面的空间
				delete(*it);
				it = childNode.erase(it);
			}
		}

	}

	//查找子结点
	TrieNode* findTier(string name) {

		//TODO:在vector v中按名查询
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
			cout << "属性：";
			for (vector<Attribute>::const_iterator iter = attribute.cbegin(); iter != attribute.cend(); iter++)
			{
				cout << (*iter).key << "-" << (*iter).value << " ";
			}
		}
		cout << endl;
	}

}Trie;

//新建人员
TrieNode* newStudent(string university, string college, string major, string _class, string name, string no, string sex) {
	TrieNode *student = new TrieNode(name);
	student->addProperty("学校", university);
	student->addProperty("学院", college);
	student->addProperty("专业", major);
	student->addProperty("班级", _class);
	student->addProperty("学号", no);
	student->addProperty("性别", sex);
	return student;
}

//将人员存入树中
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


//查找人员
void  findStudent(TrieNode *node, string name, string no, TrieNode * &student) {
	vector<TrieNode *>::iterator itr = node->childNode.begin();

	if (node != NULL &&node->level_name == name&&node->findProperty("学号") == no) {
		student = node;
		return;
	}
	while (itr != node->childNode.end())
	{
		findStudent(*itr, name, no, student);

		++itr;
	}
}


//删除学生

void deldeteStudent(TrieNode *root, string name, string no) {
	TrieNode*student = NULL;
	findStudent(root, name, no, student);

	if (student != NULL) {
		root->findTier(student->findProperty("学院"))->findTier(student->findProperty("专业"))
			->findTier(student->findProperty("班级"))->deleteNode(name);//deleteNode中有释放空间的操作
	}
	else cout << "没有该学生！" << endl;

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


// 解析json格式
void Json_Analysis(const char* text, vector<TrieNode *>&students) {
	cJSON *json, *json_name, *json_university, *json_college, *json_major, *json_class,
		*json_no, *json_sex;

	json = cJSON_Parse(text); //解析成json形式,使用该函数会通过malloc()函数在内存中开辟一个空间，使用完成需要手动释放。
	json_name = cJSON_GetObjectItem(json, "name");  //获取键值内容
	json_university = cJSON_GetObjectItem(json, "university");
	json_college = cJSON_GetObjectItem(json, "college");
	json_major = cJSON_GetObjectItem(json, "major");
	json_class = cJSON_GetObjectItem(json, "class");
	json_no = cJSON_GetObjectItem(json, "no");
	json_sex = cJSON_GetObjectItem(json, "sex");


	TrieNode *student = new TrieNode(json_name->valuestring);	//将CJSON形式转换为char *
	student->addProperty("学校", json_university->valuestring);
	student->addProperty("学院", json_college->valuestring);
	student->addProperty("专业", json_major->valuestring);
	student->addProperty("班级", json_class->valuestring);
	student->addProperty("学号", json_no->valuestring);
	student->addProperty("性别", json_sex->valuestring);

	students.push_back(student);

	cJSON_Delete(json);  //释放内存 

}

// 从文件中读取json格式的数据，返回一棵树的根节点
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

	//遍历
	vector<TrieNode*>::iterator it = students.begin();
	//先建立一个根节点

	TrieNode* Root = new TrieNode((*it)->attribute[0].value);

	while (it != students.end()) {
		TrieNode* test = Root;
		//由于读取入学生时，将学院、专业等属性存入了其属性vector中，vector中下标1，2，3分别对应学院、专业、班级
		for (int i = 1; i < 4; i++) {

			if (test->findTier((*it)->attribute[i].value)) {//如果该结点在树中已经存在
			}
			else {
				TrieNode* t = new TrieNode((*it)->attribute[i].value);
				test->addNextTier(t);
			}
			test = test->findTier((*it)->attribute[i].value);

		}
		test->addNextTier(*it);//把学生增加进树
		it++;
	}
	return Root;
}


void findPeople(TrieNode * root, vector<TrieNode *>&students) {
	//深度优先搜索出所有学生结点
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

// 将数据保存为json格式
void Save_To_Json(TrieNode * root) {
	vector<TrieNode *>students;
	findPeople(root, students);

	ofstream fout;
	fout.open("E:\\test.json");


	vector<TrieNode *>::iterator itr = students.begin();
	while (itr != students.end())
	{
		//使用字符串拼接的方式组成json格式
		/*string s = "\{\"name\":\""+(*itr)->level_name+ "\"\,"+"\"university\":\""+ (*itr)->attribute[0].value + "\"\," + "\"college\":\"" + (*itr)->attribute[1].value
		+ "\"\," + "\"major\":\"" + (*itr)->attribute[2].value + "\"\," + "\"class\":\"" + (*itr)->attribute[3].value + "\"\," + "\"no\":\"" + (*itr)->attribute[4].value
		+ "\"\," + "\"sex\":\"" + (*itr)->attribute[5].value+"\"\}";*/


		cJSON * usr;
		usr = cJSON_CreateObject();   //创建根数据对象
		cJSON_AddStringToObject(usr, "name", (*itr)->level_name.c_str());  //加入键值，加字符串
		cJSON_AddStringToObject(usr, "university", (*itr)->attribute[0].value.c_str());
		cJSON_AddStringToObject(usr, "college", (*itr)->attribute[1].value.c_str());
		cJSON_AddStringToObject(usr, "major", (*itr)->attribute[2].value.c_str());
		cJSON_AddStringToObject(usr, "class", (*itr)->attribute[3].value.c_str());
		cJSON_AddStringToObject(usr, "no", (*itr)->attribute[4].value.c_str());
		cJSON_AddStringToObject(usr, "sex", (*itr)->attribute[5].value.c_str());
		string s1 = cJSON_Print(usr);   //将json形式打印成正常字符串形式
		string s;

		//去掉CJSON生成的字符串中的 回车和制表符
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

	GuiDa->deleteNode("计算机科学与技术学院"); 


	TrieNode *LvKou = newStudent("贵州大学", "数统学院", "统计", "统计161", "吕口", "1600170075", "男");
	addStudent(GuiDa, "数统学院", "统计", "统计161", LvKou);

	TrieNode *student;
	findStudent(GuiDa, "吕口", "1600170075", student);
	//cout << student->level_name << endl;

	//deldeteStudent(GuiDa, "张繁盛", "1600170086");

	
	//output(GuiDa);
	//Save_To_Json(GuiDa);


	system("pause");
	return 0;
}

