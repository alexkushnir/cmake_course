struct S
{
    int i;
};

int main()
{
    char a[10];
    a[10] = 0;
    S* s = nullptr;
    
    s->i = 5;
    return 0;
}
