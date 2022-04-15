int main() 
{

    int a, b, result = 0, m, n;   

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    m = a;
    n =  b;

    while(n > 0)
    {                
        if(n % 2 != 0)
        {
            result += m;
        }    

        m *= 2;         
        n /= 2;  
    }

    printf("%d * %d = %d", a, b, result);

    return 0;
}