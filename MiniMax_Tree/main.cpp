#include"stdio.h"
#include"stdlib.h"
#include"string.h"

struct TreeNode{
	int value;
	int level;
	bool mini_max;
	TreeNode* chlid; // ¥ª¤l¾ð
	TreeNode* brother; // ¥k¤l¾ð
};

int Open_file(const char* file_path, TreeNode* data_buf);

int main(int argc, char**argv){
	TreeNode data[1000];
	char* file = "1.txt";
	int data_num;
	data_num = Open_file(file, data);
	return 0;
}

int Open_file(const char* file_path, TreeNode* data_buf){
	FILE* file = fopen(file_path, "r");
	if (NULL == file){
		return -1;
	}
	char file_buf[2000];
	fread(file_buf, 1, sizeof(file_buf), file);

	const char* cut = ",";
	char* output;
	int data_index = 0;
	output = strtok(file_buf, cut);
	while (output){
		data_buf[data_index].value = atoi(output);
		data_index++;
		output = strtok(NULL, cut);
	}return data_index;
}