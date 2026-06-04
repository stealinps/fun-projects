%:include <iostream>
%:include <ctime>

void display(int arr<::>,int sizes)<%
	std::cout<<"[";
	for(int i=0;i<sizes-1;i++)<%
		std::cout<<arr[i]<<",";
	%>
	std::cout<<arr[sizes-1]<<"]\n";
%>

void shuffle(int arr<::>,int sizes)<%
	for(int i=0;i<std::rand()%11;i++)<%
	int n=std::rand()%sizes;
	int m=std::rand()%sizes;
	int temp=arr<:n:>;
	arr<:n:>=arr<:m:>;
	arr<:m:>=temp;
	%>
%>

bool check(int arr<::>,int sizes) <%
	for(int i=1;i<sizes;i++) if(arr<:i:><arr<:i-1:>) return false;
	return true;
%>

int main()<%
	srand(time(NULL));
	int sizes=10;
	int arr<:sizes:>=<%9,3,1,6,10,7,4,2,5,8%>;
	bool sorted=false;
	int swap=0;
	while(!sorted)<%
		shuffle(arr,sizes);
		std::cout<<"Sort Attempt:"<<swap;
		swap++;
		display(arr,sizes);
		sorted=check(arr,sizes);
		
	%>
%>
