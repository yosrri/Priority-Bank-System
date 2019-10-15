#include <stdio.h>
#include <stdlib.h>
/*
 * Item: Each Item has a customer name and a balance.
 *       and an integer order(it is used to handle the case when two items have same priority)
*/
typedef struct
{
    char* cName;
    double balance;
    int order;
} Item;
/*
 * Heapify index i in array of Items with size n
 */
//this heapify the parent im sending only without recursing to the rest of the tree
void max_heapify(Item *arr, int n, int i)
{
    Item temp;




    //check if the parent got a first child or not
    if(i*2>n)
    {
    }
    //if he got one then go in and see id they are of the same key then check by their order *Priority*
    else
    {

        if(arr[i].balance==arr[i*2].balance)
        {
            if(arr[i].order>arr[i*2].order)
            {
                //and swap them if the order of the parent is bigger than the parent
                temp = arr[i];
                arr[i]=arr[i*2];
                arr[i*2] = temp;

            }
        }
        //if the parent is smaller than its child the swap them
        else if(arr[i].balance<arr[i*2].balance)
        {
            temp = arr[i];
            arr[i]=arr[i*2];
            arr[i*2] = temp;
            //heapify the parent who got swapped in case it changed the property of the max heap
            max_heapify(arr,n,i*2);

        }

    }
    //check if the parent got a second child or not
    if(i*2+1>n)
    {

    }
    else
    {
        //if he got one then go in and see id they are of the same key then check by their order *Priority*

        if(arr[i].balance==arr[i*2+1].balance)
        {
            if(arr[i].order>arr[i*2+1].order)
            {
                //and swap them if the order of the parent is bigger than the parent

                temp = arr[i];
                arr[i]=arr[i*2+1];
                arr[i*2+1] = temp;
            }
        }
        else if(arr[i].balance<arr[i*2+1].balance)
        {
            temp = arr[i];
            arr[i]=arr[i*2+1];
            arr[i*2+1] = temp;
            //heapify the parent who got swapped in case it changed the property of the max heap
            max_heapify(arr,n,i*2+1);

        }

    }




    /* TODO: ADD YOUR CODE HERE */
}
/*
 * Construct Priority queue from the given array of Items with size n(Build Max Heap)
 */
//calls the max_heapify with a parent and decrement to send the next parent etc..
void construct_PQ(Item*arr,int n)
{
    int i;

    for(i=n/2; i>=1; i--)

    {
        max_heapify(arr,n,i);

    }
    /* TODO: ADD YOUR CODE HERE */
}
/*
 * delete the item with max priority and then return it.
 */
Item extract_maximum(Item*arr,int n)
{
    Item temp;


    //saving the first aka largest object in temp
    temp = arr[1];
    //putting the last element in the array aka smallest object in the first place and then heapifying
    arr[1]=arr[n];

    //ask the TA about it,if its a good or bad implementation probably its bad
    construct_PQ(arr,n--);
   // max_heapify(arr,n--,1);// if i put this line then i need to call maxheapify in the balance equal balance if

    return temp;


    /* TODO: ADD YOUR CODE HERE */
}
/*
 * read array of items from file in arr and return its size.
 */
int fillArrayFromFile(char*fname,Item*arr)
{
    //starting from 1 because in heap sort we start from one to make the formula to find the children easier
    int i = 1;

    arr->cName = NULL;
    FILE * fp = fopen(fname,"r");
    if(!fp)
    {
        printf("File Not Found!");
        exit(0);
    }

    else
    {
        while(!feof(fp))
        {


            arr[i].cName = (char*)malloc(sizeof(char)*10);

            fscanf(fp," %s",arr[i].cName);
            printf("%s\t",arr[i].cName);

            fscanf(fp,"%lf",&arr[i].balance);
            printf("%.1lf\t",arr[i].balance);
            arr[i].order = i;
            printf("%d\n",arr[i].order);

            ++i;


        }
        printf("______________________________________\n");


        return i;

    }
    fclose(fp);


    /* TODO: ADD YOUR CODE HERE */
}
/*
 * print customer names in decreasing order according their priority.
 */
void printCustomersbyPriority(Item*arr,int n)
{
    int x = n;

    while(x-1)
    {
        Item temp =extract_maximum(arr,n);
        printf("%s\t%.1lf\t%d\n",temp.cName,temp.balance,temp.order);
        x--;
    }


    /* TODO: ADD YOUR CODE HERE */
}
/*
 *
 */
int main(int argc, char**argv)
{

    if(argc!=2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }
    Item *customers=(Item*)malloc(sizeof(Item)*1000);
    int arrLength=fillArrayFromFile(argv[1],customers);
    arrLength = arrLength;
    construct_PQ(customers,arrLength);

    printCustomersbyPriority(customers,arrLength);
    return 0;
}
