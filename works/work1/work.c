#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 学习记录结构体
struct StudyRecord {
    time_t startTime;
    time_t endTime;
    double elapsedTime;
    char fileName[50];
};

// 学习时间统计结构体
struct AccumulatedTime {
    double totalTime;
};

// 章节和小节信息
struct Section {
    char name[50];
};

// 章节和小节数据
struct Section sections[] = {
        {"A Tutorial Introduction"},
    {"Types, Operators and Expressions"},
    {"Control Flow"},
    {"Functions and Program Structure"},
    {"Pointers and Arrays"},
    {"Structures"},
    {"Input and Output"},
};

// 显示菜单
void displayMenu() {
    printf("章节菜单:\n");
    int i = 0;
    for (; i < sizeof(sections) / sizeof(sections[0]); ++i) {
        printf("%d %s\n", i + 1, sections[i].name);
    }
}


// 记录学习时间
void recordStudyTime(struct StudyRecord *record) {
    time(&record->endTime);
    record->elapsedTime = difftime(record->endTime, record->startTime);
}

// 显示学习记录
void displayStudyRecord(struct StudyRecord *record) {
    printf("开始时间: %s", ctime(&record->startTime));
    printf("结束时间: %s", ctime(&record->endTime));
    printf("学习时间: %.2f秒\n", record->elapsedTime);
    printf("打开文件: %s\n", record->fileName);
}

// 记录累积学习时间
void updateAccumulatedTime(struct AccumulatedTime *accumulatedTime, double elapsedTime) {
    accumulatedTime->totalTime += elapsedTime;
}

// 显示累积学习时间
void displayAccumulatedTime(struct AccumulatedTime *accumulatedTime) {
    printf("累积学习时间: %.2f秒\n", accumulatedTime->totalTime);
}

int main() {
    int sectionIndex, subsectionIndex;
    char studentID[20];
    struct StudyRecord studyRecord;
    struct AccumulatedTime accumulatedTime = {0};

    printf("请输入您的学号: ");
    scanf("%s", studentID);

    while (1) {
        displayMenu();

        printf("请输入章节编号(输入0退出): ");
        scanf("%d", &sectionIndex);

        if (sectionIndex == 0) {
            break;
        }

        if (sectionIndex < 1 || sectionIndex > sizeof(sections) / sizeof(sections[0])) {
            printf("无效的章节编号，请重新输入。\n");
            continue;
        }


        // 记录学习时间
        time(&studyRecord.startTime);
        snprintf(studyRecord.fileName, sizeof(studyRecord.fileName), "%s_%s.txt", studentID);
        FILE *fp;
        int c;
		switch(sectionIndex){
        	case 1:
        		fp = fopen("章节01 含小节和知识点编号.txt","r");
        		break; 
        	case 2:
        		fp = fopen("章节02 含小节和知识点编号.txt","r");
        		break;
        	case 3:
        	    fp = fopen("章节03 含小节和知识点编号.txt","r");
        	    break;
        	case 4:
        		fp = fopen("章节04 含小节和知识点编号.txt","r");
        		break;
        	case 5:
        		fp = fopen("章节05 含小节和知识点编号.txt","r");
        		break;
        	case 6:
        	    fp = fopen("章节06 含小节和知识点编号.txt","r");
        	    break;
        	case 7:
        		fp = fopen("章节07 含小节和知识点编号.txt","r");
        		break;
		}
        while(1){
          c = fgetc(fp);
          if( feof(fp) ){ 
          break ;
          }
          printf("%c", c);
        }
        fclose(fp);
        // 在这里打开知识点文件并进行学习，这里仅作示例，实际需根据需要修改
        printf("学习中...请在文件中查看知识点。学习结束请输入0。\n");
        int end = 1; 
        scanf("%d",&end);
        if(end == 0){
        	recordStudyTime(&studyRecord);
        // 更新累积学习时间
        updateAccumulatedTime(&accumulatedTime, studyRecord.elapsedTime);

        // 显示学习记录
            displayStudyRecord(&studyRecord);
		}

    }

    // 显示累积学习时间
    displayAccumulatedTime(&accumulatedTime);

    return 0;
}
