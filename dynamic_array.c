#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct student {
  char name[20];  // 20bytes
  int id; // 4bytes
  int birthdate_day, birthdate_month, birthdate_year; // 12bytes
  int score; // 4bytes
  // total 40 bytes
}Student;

Student *createStdArray(int length, Student *stdPtr){

  for(int i = 0; i < length; i++)
  {
    printf("\nEnter details of student [%d]:\n", i+1);
    printf("\nEnter First name: ");
    scanf(" ");
    scanf("%s",  (stdPtr+i)->name);
    printf("\nEnter id: ");
    scanf("%d",  &(stdPtr+i)->id);
    printf("\nEnter birthdate day: ");
    scanf("%d",  &(stdPtr+i)->birthdate_day);
    printf("\nEnter birthdate month: ");
    scanf("%d",  &(stdPtr+i)->birthdate_month);
    printf("\nEnter birthdate year: ");
    scanf("%d",  &(stdPtr+i)->birthdate_year);
    printf("\nEnter score: ");
    scanf("%d",  &(stdPtr+i)->score);
    }

    printf("\nEntered students are:\n");

    for(int i = 0; i < length; i++)
    {
      printf("%30s \t %5d \t %5d \t %5d \t %5d \t %5d\n", (stdPtr+i)->name, (stdPtr+i)->id , (stdPtr+i)->birthdate_day , (stdPtr+i)->birthdate_month, (stdPtr+i)->birthdate_year , (stdPtr+i)->score);

    }
    return stdPtr;
}
Student *insertAtFront(int length, Student *stdPtr){
  Student *stdTemp = (Student*)malloc(length* sizeof(Student));
  for(int i = 0; i < length ; i++){
    *(stdTemp+i) = *(stdPtr+i);
  }
  stdPtr = (Student*)realloc(stdPtr,(length+1)*sizeof(Student));

  printf("\n\nEnter details of the new student:\n");
  printf("\nEnter First name: ");
  scanf(" ");
  scanf("%s",  (stdPtr+0)->name);
  printf("\nEnter id: ");
  scanf("%d",  &(stdPtr+0)->id);
  printf("\nEnter birthdate day: ");
  scanf("%d",  &(stdPtr+0)->birthdate_day);
  printf("\nEnter birthdate month: ");
  scanf("%d",  &(stdPtr+0)->birthdate_month);
  printf("\nEnter birthdate year: ");
  scanf("%d",  &(stdPtr+0)->birthdate_year);
  printf("\nEnter score: ");
  scanf("%d",  &(stdPtr+0)->score);

  for(int i = 1; i < length +1; i++){
    stdPtr[i] = stdTemp[i-1];
  }

  printf("\nEntered students are:\n");

  for(int i = 0; i < length +1; i++)
  {
    printf("%30s \t %5d \t %5d \t %5d \t %5d \t %5d\n", (stdPtr+i)->name, (stdPtr+i)->id , (stdPtr+i)->birthdate_day , (stdPtr+i)->birthdate_month, (stdPtr+i)->birthdate_year , (stdPtr+i)->score);

  }
  return stdPtr;
}

Student *insertAtPosition(int position, int length, Student *stdPtr){
  Student *stdTemp = (Student*)malloc(length* sizeof(Student));
  for(int i = position; i < length ; i++){
    *(stdTemp+i) = *(stdPtr+i);
  }
  stdPtr = (Student*)realloc(stdPtr,(length+1)*sizeof(Student));

  printf("\n\nEnter details of the new student:\n");
  printf("\nEnter First name: ");
  scanf(" ");
  scanf("%s",  (stdPtr+position)->name);
  printf("\nEnter id: ");
  scanf("%d",  &(stdPtr+position)->id);
  printf("\nEnter birthdate day: ");
  scanf("%d",  &(stdPtr+position)->birthdate_day);
  printf("\nEnter birthdate month: ");
  scanf("%d",  &(stdPtr+position)->birthdate_month);
  printf("\nEnter birthdate year: ");
  scanf("%d",  &(stdPtr+position)->birthdate_year);
  printf("\nEnter score: ");
  scanf("%d",  &(stdPtr+position)->score);

  for(int i = position+1; i < length +1; i++){
    stdPtr[i] = stdTemp[i-1];
  }

  printf("\nEntered students are:\n");

  for(int i = 0; i < length +1; i++)
  {
    printf("%30s \t %5d \t %5d \t %5d \t %5d \t %5d\n", (stdPtr+i)->name, (stdPtr+i)->id , (stdPtr+i)->birthdate_day , (stdPtr+i)->birthdate_month, (stdPtr+i)->birthdate_year , (stdPtr+i)->score);

  }
  return stdPtr;
}


Student *insertAtEnd(int length, Student *stdPtr){
  stdPtr = (Student*)realloc(stdPtr, (length+1)*sizeof(Student));
  printf("\n\nEnter details of the new student:\n");
  printf("\nEnter First name: ");
  scanf(" ");
  scanf("%s",  (stdPtr+length)->name);
  printf("\nEnter id: ");
  scanf("%d",  &(stdPtr+length)->id);
  printf("\nEnter birthdate day: ");
  scanf("%d",  &(stdPtr+length)->birthdate_day);
  printf("\nEnter birthdate month: ");
  scanf("%d",  &(stdPtr+length)->birthdate_month);
  printf("\nEnter birthdate year: ");
  scanf("%d",  &(stdPtr+length)->birthdate_year);
  printf("\nEnter score: ");
  scanf("%d",  &(stdPtr+length)->score);

  printf("\nEntered students are:\n");

  for(int i = 0; i < length +1; i++)
  {
    printf("%30s \t %5d \t %5d \t %5d \t %5d \t %5d\n", (stdPtr+i)->name, (stdPtr+i)->id , (stdPtr+i)->birthdate_day , (stdPtr+i)->birthdate_month, (stdPtr+i)->birthdate_year , (stdPtr+i)->score);

  }
  return stdPtr;

}

int main()
{
  printf("Enter the number of elements of the dynamic array (positive integer): ");
  int n;
  scanf (" %d", &n);
  if (n<=0){
    printf("\ninvalid input\n");
  }
  else {
  Student *stdPtr = (Student*)malloc(n* sizeof(Student)); // pointer to the student structure
  printf("\nThe size of the dynamic array: %d ",  sizeof(Student));
  printf("\nThe size of the dynamic array: %d\n",  n* sizeof(Student));

  clock_t begin1 = clock();
  stdPtr = createStdArray(n,stdPtr);
  clock_t end1 = clock();
  double time_spent1 = (double)(end1 - begin1)/ CLOCKS_PER_SEC;
  printf("\n\nTime consumed by the insert at the end function: %f\n", time_spent1);

  printf("\n\nInsert a new element at the Front of the array: ");
  clock_t begin2 = clock();
  stdPtr = insertAtFront(n,stdPtr);
  clock_t end2 = clock();
  double time_spent2 = (double)(end2 - begin2)/ CLOCKS_PER_SEC;
  printf("\n\nTime consumed by the insert at the Front function: %f\n", time_spent2);

  printf("\n\nInsert a new element at a position of the array: ");
  printf("\nEnter the position of the new element (positive integer): ");

  int p;
  scanf (" %d", &p);

  if (p > 0  && p < n+1){

    clock_t begin3 = clock();
    stdPtr = insertAtPosition(p, n+1, stdPtr);
    clock_t end3 = clock();
    double time_spent3 = (double)(end3 - begin3)/ CLOCKS_PER_SEC;
    printf("\n\nTime consumed by the insert at a position function: %f\n", time_spent3);

    printf("\n\nInsert a new element at the End of the array: ");

    clock_t begin4 = clock();
    stdPtr = insertAtEnd(n+2,stdPtr);
    clock_t end4 = clock();
    double time_spent4 = (double)(end4 - begin4)/ CLOCKS_PER_SEC;
    printf("\n\nTime consumed by the insert at the end function: %f\n", time_spent4);

    printf("\nThe size of the dynamic array after the three insertion operations: %d\n",  (n+3)* sizeof(Student));
}

  else {
    printf("\ninvalid input\n");
  }



  free(stdPtr);
}

  return 0;
  }
