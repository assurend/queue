int main()
{
    int i, k;
    printf("Enter 5 elements:");
    for(i=0; i<5; i++)
    {
        scanf("%d", &k);
        push(k);
    }
    
    printf("Elements in queue are:");
    for(i=0; i<5; i++)
    {
        printf("%d\t", pop());
        push(k);
    }
    return 0;
}
