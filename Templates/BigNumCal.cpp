#include<iostream>

const int LEN=100;

int a[LEN],b[LEN],c[LEN],d[LEN];

void add(int a[],int b[],int c[])
{
    for(int i=0;i<LEN;++i) c[i]=0;
    int t=0;
    for(int i=0;i<LEN;++i)
    {
        c[i]=a[i]+b[i];
        c[i]+=t;
        t=c[i]/10;
        c[i]%=10;
    }
}
void substrack(int a[],int b[],int c[])
{
    for(int i=0;i<LEN;++i) c[i]=0;
    int t=0;
    for(int i=0;i<LEN-1;++i)
    {
        c[i]=a[i]-b[i]+t;
        if(c[i]<0) {t=-1;c[i]+=10;}
    }
}

void multi(int a[],int b[],int c[])
{
    for(int i=0;i<LEN;++i) c[i]=0;
    
    for(int i=0;i<LEN;++i)
    {
        for(int j=0;j<=i;++j)
            c[i]+=a[j]*b[i-j];
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
}
void mul(int a[],int b[],int c[])
{
    for(int i=0;i<LEN;++i) c[i]=0;

    for(int i=0;i<LEN;++i)
    {
        for(int j=0;j<=i;++j)
            c[i]+=a[i-j]*b[j];
        c[i+1]=c[i]/10;
        c[i]%=10;
    }
}


// 被除数 a 以下标 last_dg 为最低位，是否可以再减去除数 b 而保持非负
// len 是除数 b 的长度，避免反复计算
inline bool greater_eq(int a[], int b[], int last_dg, int len) {
  // 有可能被除数剩余的部分比除数长，这个情况下最多多出 1 位，故如此判断即可
  if (a[last_dg + len] != 0) return true;
  // 从高位到低位，逐位比较
  for (int i = len - 1; i >= 0; --i) {
    if (a[last_dg + i] > b[i]) return true;
    if (a[last_dg + i] < b[i]) return false;
  }
  // 相等的情形下也是可行的
  return true;
}

void div(int a[], int b[], int c[], int d[]) {
    for(int i=0;i<LEN;++i) {c[i]=0;d[i]=0;}


  int la, lb;
  for (la = LEN - 1; la > 0; --la)
    if (a[la - 1] != 0) break;
  for (lb = LEN - 1; lb > 0; --lb)
    if (b[lb - 1] != 0) break;
  if (lb == 0) {
    puts("ERROR");
    return;
  }  // 除数不能为零

  // c 是商
  // d 是被除数的剩余部分，算法结束后自然成为余数
  for (int i = 0; i < la; ++i) d[i] = a[i];
  for (int i = la - lb; i >= 0; --i) {
    // 计算商的第 i 位
    while (greater_eq(d, b, i, lb)) {
      // 若可以减，则减
      // 这一段是一个高精度减法
      for (int j = 0; j < lb; ++j) {
        d[i + j] -= b[j];
        if (d[i + j] < 0) {
          d[i + j + 1] -= 1;
          d[i + j] += 10;
        }
      }
      // 使商的这一位增加 1
      c[i] += 1;
      // 返回循环开头，重新检查
    }
  }
}


int main()
{
    b[0]=a[0]=1;
    b[1]=a[1]=2;
    b[2]=a[2]=3;
    b[3]=a[3]=4;
    b[4]=a[4]=5;
    b[5]=a[5]=6;
    b[6]=a[6]=7;
    add(a,b,c);
    int i;
    for(i=LEN-1;c[i]==0;--i);
    for(;i>=0;--i) printf("%d",c[i]);
    printf("\n");
    a[9]=1;

    substrack(a,b,c);
    for(i=LEN-1;c[i]==0;--i);
    for(;i>=0;--i) printf("%d",c[i]);
    printf("\n");

    mul(a,b,c);
    for(i=LEN-1;c[i]==0;--i);
    for(;i>=0;--i) printf("%d",c[i]);
    printf("\n");
    for(i=LEN-1;a[i]==0;--i);
    for(;i>=0;--i) printf("%d",a[i]);
    printf("\n");
    for(i=LEN-1;b[i]==0;--i);
    for(;i>=0;--i) printf("%d",b[i]);
    printf("\n");
    div(a,b,c,d);
    for(i=LEN-1;c[i]==0;--i);
    for(;i>=0;--i) printf("%d",c[i]);
    printf("\n");
    for(i=LEN-1;d[i]==0;--i);
    for(;i>=0;--i) printf("%d",d[i]);
    return 0;
}










// #include<iostream>
// #include<string>
// #include<algorithm>
// #include<cstring>

// int length(char* a)
// {
// 	int i;
// 	for (i = 1; a[i] != 0; ++i);
// 	return i;
// }

// void reverse(char* a)
// {
// 	char temp;
// 	int n = length(a);
// 	if (!n) return;
// 	for (int i = 0; i < n / 2; ++i)
// 	{
// 		temp = a[i];
// 		a[i] = a[n - 1 - i];
// 		a[n - 1 - i] = temp;
// 	}
// }
// int main()
// {
// 	int N, n;
// 	std::cin >> N;
// 	n = N;
// 	while (N--)
// 	{
// 		int f1 = 1, f2 = 1, f3 = -1;
// 		char A[15], B[15], C[15];
// 		std::cin >> A >> B >> C;

// 		if (A[0] == '-') { f1 = -1; A[0] = 0; }
// 		if (B[0] == '-') { f2 = -1; B[0] = 0; }
// 		if (C[0] == '-') { f3 = 1; C[0] = 0; }
// 		char sum[18]="00000000000000000";

// 		reverse(A), reverse(B), reverse(C);
// 		int a = length(A), b = length(B), c = length(C);
// 		int i;
// 		for (i = 0; i < a || i < b || i < c; ++i)
// 		{
// 			int temp = 0;
// 			if (a > i) temp += (A[i] - '0') * f1;
// 			if (b > i) temp += (B[i] - '0') * f2;
// 			if (c > i) temp += (C[i] - '0') * f3;

// 			sum[i + 1] += temp / 10;
// 			sum[i] = temp % 10 + sum[i];

// 			if (sum[i] > '9')
// 			{
// 				sum[i] -= 10;
// 				sum[i + 1] += 1;
// 			}
// 			else if (sum[i] < '0')
// 			{
// 				sum[i] += 10;
// 				sum[i + 1] -= 1;
// 			}

// 		}
// 		sum[i+1] = 0;
// 		reverse(sum);
// 		bool flag=true;
// 		int count = 0;
// 		for (i = 0; i < length(sum); ++i)
// 		{ 
// 			if (sum[i] < '0')
// 			{
// 				flag = false;
// 				break;
// 			}
// 			else if(sum[i] == '0')
// 				++count;
// 		}
// 		if (count == i) flag = false;
// 		if (flag) printf("Case #%d: true\n", n - N );
// 		else printf("Case #%d: false\n", n - N );
// 	}
// 	return 0;
// }

//another version

// void plus()
// {
// 	int temp=0;
// 	int i=0,len=max(strlen(num1),strlen(num2))+1;
// 	char rnum1[51],rnum2[51],rresult[101];
// 	for(int i=num1_length-1;i>-1;--i) rnum1[temp++]=num1[i];
// 	temp=0;
// 	for(int i=num2_length-1;i>-1;--i) rnum2[temp++]=num2[i];
// 	temp=0;

// 	for(;i<len-1;++i)
// 	{
// 		if(i<num1_length) temp+=rnum1[i]-'0';
// 		if(i<num2_length) temp+=rnum2[i]-'0';
// 		rresult[i]=temp%10+'0';
// 		temp/=10;
// 	}
// 	if(temp!=0) rresult[i]=temp;
// 	else len--;
// 	for(int i=0;i<len;++i) result[i]=rresult[len-i-1];
// 	result[len]=0;
// }

// void minus()
// {
// 	int borrow=0,len=num1_length,temp=0;

// 	char rnum1[51],rnum2[51],rresult[101];
// 	if(num1_length>num2_length||num1_length==num2_length&&strcmp(num1,num2))
// 	{
// 		for(int i=num1_length-1;i>-1;--i) rnum1[temp++]=num1[i];
// 		temp=0;
// 		for(int i=num2_length-1;i>-1;--i) rnum2[temp++]=num2[i];
// 		temp=0;
// 	}
// 	else
// 	{
// 		np=0;
// 		for(int i=num2_length-1;i>-1;--i) rnum1[temp++]=num2[i];
// 		temp=0;
// 		for(int i=num1_length-1;i>-1;--i) rnum2[temp++]=num1[i];
// 		temp=0;
// 	}

// 	for(int i=0;i<len;++i)
// 	{
// 		temp=rnum1[i]-'0'-borrow-(i>num2_length?0:rnum2[i]-'0')+10;
// 		rresult[i]=temp%10+'0';
// 		borrow=temp/10?0:1;
// 	}

// 	for(int i=0;i<len;++i) result[i]=rresult[len-i-1];
// 	result[len]=0;

// }
// void multi()
// {
// 	int temp=0,j;
// 	char rnum1[51],rnum2[51],rresult[101];
// 	for(int i=0;i<101;++i) rresult[i]='0';
// 	for(int i=num1_length-1;i>-1;--i) rnum1[temp++]=num1[i];
// 	temp=0;
// 	for(int i=num2_length-1;i>-1;--i) rnum2[temp++]=num2[i];
// 	temp=0;

// 	for(int i=0;i<num1_length;++i)
// 	{
// 		for(j=0;j<num2_length;++j)
// 		{
// 			temp+=(num1[i]-'0')*(num2[j]-'0')+rresult[i+j]-'0';
// 			rresult[i+j]=temp%10+'0';
// 			temp/=10;
// 		}

// 		for(;j+i<num2_length+num1_length;++j)
// 		{
// 			temp+=rresult[i+j]-'0';
// 			rresult[i+j]=temp%10+'0';
// 			temp/=10;
// 		}
// 	}
// 	for(int i=0;i<num2_length+num1_length;++i) result[i]=rresult[num1_length+num2_length-i-1];
// }
