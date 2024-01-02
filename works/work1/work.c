#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ѧϰ��¼�ṹ��
struct StudyRecord {
    time_t startTime;
    time_t endTime;
    double elapsedTime;
    char fileName[50];
};

// ѧϰʱ��ͳ�ƽṹ��
struct AccumulatedTime {
    double totalTime;
};

// �½ں�С����Ϣ
struct Section {
    char name[50];
};

// �½ں�С������
struct Section sections[] = {
        {"A Tutorial Introduction"},
    {"Types, Operators and Expressions"},
    {"Control Flow"},
    {"Functions and Program Structure"},
    {"Pointers and Arrays"},
    {"Structures"},
    {"Input and Output"},
};

// ��ʾ�˵�
void displayMenu() {
    printf("�½ڲ˵�:\n");
    int i = 0;
    for (; i < sizeof(sections) / sizeof(sections[0]); ++i) {
        printf("%d %s\n", i + 1, sections[i].name);
    }
}


// ��¼ѧϰʱ��
void recordStudyTime(struct StudyRecord *record) {
    time(&record->endTime);
    record->elapsedTime = difftime(record->endTime, record->startTime);
}

// ��ʾѧϰ��¼
void displayStudyRecord(struct StudyRecord *record) {
    printf("��ʼʱ��: %s", ctime(&record->startTime));
    printf("����ʱ��: %s", ctime(&record->endTime));
    printf("ѧϰʱ��: %.2f��\n", record->elapsedTime);
    printf("���ļ�: %s\n", record->fileName);
}

// ��¼�ۻ�ѧϰʱ��
void updateAccumulatedTime(struct AccumulatedTime *accumulatedTime, double elapsedTime) {
    accumulatedTime->totalTime += elapsedTime;
}

// ��ʾ�ۻ�ѧϰʱ��
void displayAccumulatedTime(struct AccumulatedTime *accumulatedTime) {
    printf("�ۻ�ѧϰʱ��: %.2f��\n", accumulatedTime->totalTime);
}

int main() {
    int sectionIndex, subsectionIndex;
    char studentID[20];
    struct StudyRecord studyRecord;
    struct AccumulatedTime accumulatedTime = {0};

    printf("����������ѧ��: ");
    scanf("%s", studentID);

    while (1) {
        displayMenu();

        printf("�������½ڱ��(����0�˳�): ");
        scanf("%d", &sectionIndex);

        if (sectionIndex == 0) {
            break;
        }

        if (sectionIndex < 1 || sectionIndex > sizeof(sections) / sizeof(sections[0])) {
            printf("��Ч���½ڱ�ţ����������롣\n");
            continue;
        }


        // ��¼ѧϰʱ��
        time(&studyRecord.startTime);
        snprintf(studyRecord.fileName, sizeof(studyRecord.fileName), "%s_%s.txt", studentID);
        FILE *fp;
        int c;
		switch(sectionIndex){
        	case 1:
        		fp = fopen("�½�01 ��С�ں�֪ʶ����.txt","r");
        		break; 
        	case 2:
        		fp = fopen("�½�02 ��С�ں�֪ʶ����.txt","r");
        		break;
        	case 3:
        	    fp = fopen("�½�03 ��С�ں�֪ʶ����.txt","r");
        	    break;
        	case 4:
        		fp = fopen("�½�04 ��С�ں�֪ʶ����.txt","r");
        		break;
        	case 5:
        		fp = fopen("�½�05 ��С�ں�֪ʶ����.txt","r");
        		break;
        	case 6:
        	    fp = fopen("�½�06 ��С�ں�֪ʶ����.txt","r");
        	    break;
        	case 7:
        		fp = fopen("�½�07 ��С�ں�֪ʶ����.txt","r");
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
        // �������֪ʶ���ļ�������ѧϰ���������ʾ����ʵ���������Ҫ�޸�
        printf("ѧϰ��...�����ļ��в鿴֪ʶ�㡣ѧϰ����������0��\n");
        int end = 1; 
        scanf("%d",&end);
        if(end == 0){
        	recordStudyTime(&studyRecord);
        // �����ۻ�ѧϰʱ��
        updateAccumulatedTime(&accumulatedTime, studyRecord.elapsedTime);

        // ��ʾѧϰ��¼
            displayStudyRecord(&studyRecord);
		}

    }

    // ��ʾ�ۻ�ѧϰʱ��
    displayAccumulatedTime(&accumulatedTime);

    return 0;
}
