
int push(char *, char, int);
char pop(char *, int);
bool isValid(char * s)
{
    int i=0,top=-1;
    char pstack[5000],op;
    while(*(s+i)!='\0')
    {
        if(*(s+i)=='{')
        {
            top=push(pstack,*(s+i),top);
            if(top>4999)
                return 0;
        }
        else if(*(s+i)=='[')
        {
            top=push(pstack,*(s+i),top);
            if(top>4999)
                return 0;
        }
        else if(*(s+i)=='(')
        {
            top=push(pstack,*(s+i),top);
            if(top>4999)
                return 0;
        }
        
        else
        {
            if(top>-1)
            {
                op=pop(pstack,top);
                top--;
                switch(op)
                {
                    case '{':
                        if(*(s+i)!='}')
                            return 0;
                        break;
                    case '[':
                        if(*(s+i)!=']')
                            return 0;
                        break;
                    case '(':
                        if(*(s+i)!=')')
                            return 0;
                        break;
                }
            }
            else
                return 0;
        }
        i++;
    }
    if(top!=-1)
        return 0;
    return 1;
}

int push(char *pstack, char para, int top)
{
    *(pstack+top+1)=para;
    top++;
    return top;
}

char pop(char *pstack, int top)
{
    return *(pstack+top);
}
