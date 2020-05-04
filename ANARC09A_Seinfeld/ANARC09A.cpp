#include <cstdio>

using namespace std;
typedef long long LL;

int main()
{
  int k=0,ans,o,c;
  while(1)
  {
    char s[2001];
    scanf("%s",s);
    if(s[0]=='-')
      break;
    o = c = 0;
    int i = 0;
    while(s[i]!='\0')
    {
      if(s[i]=='{')
        o++;
      else
      {
        o--;
        if(o<0)
        {
          o=1;
          c++;
        }
      }
      i++;
    }
    ans = c+o/2;
    printf("%d. %d\n",k+1,ans);
    k++;
  }
  return 0;
}
/*
#include <iostream>
using namespace std;
 
const int MAX = 2005;
 
char str[MAX], stack[MAX];
int  stack_leng, Answer;
 
int GetLength(char *str)
{
    int length = 0;
    while(str[length] != '\0') length++;
    return length;
}
 
int main()
{
    ios::sync_with_stdio(false);
 
    int tc = 0;
    int length;
 
    while(true)
    {
        cin >> str;
        if(str[0] == '-') break;
        
        tc++;
        stack_leng = 0;
        length       = GetLength(str);
        Answer     = 0;
 
        // cho kí tự đầu tiên vào stack
        stack[stack_leng++] = str[0];
 
        for(int i = 1; i < length; i++)
        {
            // Nếu đỉnh stack là '{' và kí tự tiếp theo cho vào là '}'
            // thì bỏ cả hai ra khỏi stack vì cặp này đã hợp lệ
            // Các trường hợp khác thì sẽ cho tiếp vào stack
            if(stack[stack_leng-1] == '{' && str[i] == '}') stack_leng--;
            else stack[stack_leng++] = str[i];
        }
 
        //
        if(stack_leng == 0) 
            Answer = 0;
        else if(stack[0] == '{') 
            // thì bắt buộc stack phải có dạng: {{{{,
            // vì nếu có dấu } thì ta đã bỏ cặp đó ra khỏi stack rồi
            Answer = stack_leng / 2;
        else // stack[0] = '}'
        {
            // duyệt từ đầu của stack
            int start = 0;
 
            while(true)
            {
                if (start >= stack_leng) break;
 
                if(stack[start] == '}' && stack[start + 1] == '}')
                {
                    Answer ++;
                    start  +=2;
                }
                else if (stack[start] == '}' && stack[start + 1] == '{')
                {
                    Answer += 2;
                    start  += 2;
                }
                else if (stack[start] == '{') 
                // thì chắc chắn các kí tự phía sau phải là {
                {
                    Answer += (stack_leng - start)/2;
                    break;
                }
            }
        }
 
        cout << tc << ". " << Answer << endl;
    }
 
    return 0;
}
*/