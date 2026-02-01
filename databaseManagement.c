#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define sizes 10 //the number of employee

void inputName(char name[sizes][50], int id[sizes]){
    int i, skip=0;
    char inputName[50];
        for(i=0; i<sizes; ++i){
            printf("第%d的输入序号:", i+1);
            scanf("%d", &id[i]);
                for(int j=0; j< i; j++){
                    if(id[i]==id[j]){
                        printf("%d重复输入, 请您再输入一遍。\n", id[i]);
                        i-=1;
                        skip = 1;
                    }
                }
            if(skip==1){
                skip=0;
                continue;
            }
                getchar();
            printf("         姓名:");
            scanf("%[^\n]", inputName); // [^\n] to skip when reach a space
                getchar();
            strcpy(name[i], inputName);
        }
}
//冒泡排序 bubble sort, to arrange the id and name
void sortName(char name[sizes][50], int id[sizes]){
    int i, j, tempId[sizes];
    char tempName[sizes][50];
    for(i=0; i< sizes-1; i++){
        for(j=0; j< sizes -i -1; j++){
            if(id[j]>id[j+1]){
                tempId[j]=id[j];
                id[j]=id[j+1];
                id[j+1]=tempId[j];
                strcpy(tempName[j], name[j]);
                strcpy(name[j], name[j+1]);
                strcpy(name[j+1], tempName[j]);
            }
        }
    }
    for(i=0; i<sizes; i++){
            printf("%d %s\n", id[i], name[i]);
        }
}
//折半查找 binary search, 线性查找 linear search
//to find the id that we try to print
void binarySearch(char name[sizes][50], int id[sizes], int searchId){
    int low = 0, high = sizes - 1, mid;
    int found;
    while(low<=high){
        mid = (low + high) / 2;
        if(searchId == id[mid]){
            printf("序号:%d  姓名:%s", searchId, name[mid]);
            found = 1;
            break;
        }else if(searchId < id[mid]){
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    if(!found){
        printf("输入错误, 序号%d不存在。", searchId);
    }
}
    int main(){
        char name[sizes][50];
        int id[sizes];
        int searchId;
            inputName(name, id);

        printf("您输入的消息：\n");
            sortName(name, id);

        printf("您要寻找的序号:");
        scanf("%d", &searchId);

            binarySearch(name, id, searchId);
        return 0;
}