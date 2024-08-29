#include<bits/stdc++.h>
#include<cmath>
#include<string>
#include<ctype.h>
using namespace std;

//question 1
// int gcd(int a, int b){
//     if (b == 0){ return a;}
//     return gcd(b, a%b);
// }
// int main()
// {
//     int a,b;
//     cout<<"enter the numbers:";
//     cin>>a>>b;
//     cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b)<< endl;
//     return 0;
// }

// question 2
// int generateFibonacci(int n) {
//     if (n <= 1) {
//         return n;
//     } else {
//         return generateFibonacci(n - 1) + generateFibonacci(n - 2);
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     if(n<0){cout<<"invalid input:enter positive integers";exit(0);}
//     for (int i = 0; i < n; ++i) {
//         cout << generateFibonacci(i) << " ";
//     }
// }

//question 3
// float calculateArea(float l,float w){
//     return l*w;
// } 
// float calculatePerimeter(float l,float w){
//     return 2*(l+w);
// }
// int main(){
//     float w,l;
//     cout<<"enter length:";
//     cin>>l;
//     cout<<"enter width:";
//     cin>>w;
//     if(w<=0 || l<=0){cout<<"invalid input:enter positive dimentions";exit(0);}
//     cout<<"area is:"<<calculateArea(l,w)<<endl;
//     cout<<"perimeter is:"<<calculatePerimeter(l,w)<<endl;
//     return 0;
// }

//question 4
// float calculateVolume(float r,float h){
//     return M_PI*r*r*h;
// } 
// float calculateSurfaceArea(float r,float h){
//     return 2*M_PI*r*(r+h);
// }
// int main(){
//     float r,h;
//     cout<<"enter radius:";
//     cin>>r;
//     cout<<"enter height:";
//     cin>>h;
//     if(h<=0 || r<=0){cout<<"invalid input:enter positive dimentions";exit(0);}
//     cout<<"volume is:"<<calculateVolume(r,h)<<endl;
//     cout<<"surface area is:"<<calculateSurfaceArea(r,h)<<endl;
// }

//question 5

// takes two dates and calculate number of days months and years
// bool isLeapYear(int year) {
//     // Leap year is divisible by 4
//     // Exception: If a year is divisible by 100, it must also be divisible by 400
//     return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
// }
// int main(){
//     int d1,m1,y1;
//     cout<<"enter initial date as DD MM YYYY:";
//     cin>>d1>>m1>>y1;
//     int d2,m2,y2;
//     cout<<"enter final date as DD MM YYYY:";
//     cin>>d2>>m2>>y2;
//     if(d1>31 ||d2>31 || m1>12||m2>12 || y1<0||y2<0){cout<<"invalid input";return 0;}
//     int months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//     int monthsleap[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
//     int n_days=0,n_months=0,n_years=0;
//     if(isLeapYear(y1)){n_days+=(monthsleap[m1]-d1);}else{n_days+=(months[m1]-d1);}
//     n_months+=(12-m1-1);
//     n_years=(y2-y1-1);
//     n_days+=d2;
//     n_months+=m2;
//     if(n_days>30){if(isLeapYear(y2)){n_days-=monthsleap[m2];n_months+=1;}else{n_days-=months[m2];n_months+=1;}}
//     if(n_months>11){n_months-=12;n_years+=1;}
//     cout<<n_years<<" years "<<n_months<<" months "<<n_days<<" days"<<endl;
//     cout<<"This day calculator counts the number of days between two dates. It does not include the last day, so, there is 1 day between today and tomorrow, not 2.";
//     return 0;
// }

// takes number of days and calculate the date after that date(not including the current day)
// bool isLeapYear(int year) {
//     // Leap year is divisible by 4
//     // Exception: If a year is divisible by 100, it must also be divisible by 400
//     return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
// }
// void calculateDate(int totalDays, int& day, int& month, int& year) {
//     const int daysInYear = 365;
//     const int daysInLeapYear = 366;
//     int daysPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     while (totalDays > 0) {
//         int daysInCurrentMonth = daysPerMonth[month];
//         if (isLeapYear(year) && month == 2) {
//             daysInCurrentMonth = 29;
//         }
//         int remainingDaysInMonth = daysInCurrentMonth - day + 1;
//         if (totalDays >= remainingDaysInMonth) {
//             totalDays -= remainingDaysInMonth;
//             day = 1;
//             month++;
//             if (month > 12) {
//                 month = 1;
//                 year++;
//             }
//         } 
//         else {
//             day += totalDays;
//             totalDays = 0;
//         }
//     }
// }
// int main() {
//     int totalDays;
//     int day;
//     int month;
//     int  year;
//     cout<<"Enter today's date as DD MM YYYY:";
//     cin>>day>>month>>year;
//     cout << "Enter total number of days: ";
//     cin >> totalDays;
//     calculateDate(totalDays, day, month, year);
//     cout << "Date after " << totalDays << " days: " << day << "/" << month << "/" << year << endl;
//     if (isLeapYear(year)) {
//         cout << year << " is a leap year." <<endl;
//     } else {
//         cout << year << " is not a leap year." <<endl;
//     }
//     return 0;
// }

// // start from jan and enter days(starts from 0000 years)
// bool isLeapYear(int year) {
//     // Leap year is divisible by 4
//     // Exception: If a year is divisible by 100, it must also be divisible by 400
//     return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
// }
// void calculateDate(int totalDays, int& day, int& month, int& year) {
//     const int daysInYear = 365;
//     const int daysInLeapYear = 366;
//     int daysPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     year = 0;
//     month = 1;
//     day = 1;
//     while (totalDays > 0) {
//         int daysInCurrentMonth = daysPerMonth[month];
//         if (isLeapYear(year) && month == 2) {
//             daysInCurrentMonth = 29;
//         } 
//         int remainingDaysInMonth = daysInCurrentMonth - day + 1;
//         if (totalDays >= remainingDaysInMonth) {
//             totalDays -= remainingDaysInMonth;
//             day = 1;
//             month++;
//             if (month > 12) {
//                 month = 1;
//                 year++;
//             }
//         } 
//         else {
//             day += totalDays;
//             totalDays = 0;
//         }
//     }
// }
// int main() {
//     int totalDays, day, month, year;
//     cout << "Enter total number of days: ";
//     cin >> totalDays;
//     calculateDate(totalDays, day, month, year);
//     cout << "Date after " << totalDays << " days: " << day << "/" << month << "/" << year << endl;
//     if (isLeapYear(year)) {
//         cout << year << " is a leap year." <<endl;
//     } else {
//         cout << year << " is not a leap year." <<endl;
//     }
//     return 0;
// }

// //question 6
// int main(){
//     string str;
//     cin>>str;
//     int n=str.size();
//     cout<<"length of string is "<<n<<endl;
//     bool var;
//     for (int i=0;i<=n/2;i++){
//         if(str[i]==str[n-1-i]){var=true;}
//         else{var=false;break;}
//     }
//     cout<<"reversed string:";
//     for (int i=n-1;i>=0;i--){
//         cout<<str[i];
//     }
//     cout<<endl;
//     if(var==true){cout<<"it is a palindrome"<<endl;}
//     else{cout<<"it is not a palindrome"<<endl;}
//     return 0;
// }

// question 7
// int main() {
//     cout<<"enter the sentence:";
//     string str;
//     getline (cin, str);
//     char array1[str.size()];
//     int store_nochar[100];
//     int j=1;
//     for(int i=0;i<str.size();i++){
//         array1[i]=str[i];
//         if(!(isalpha(str[i]))){store_nochar[j]=i;j++;}
//        }
//     store_nochar[0]=-1;
//     store_nochar[j]=str.size();
//     for(int i=0;i<str.size();i++){cout<<array1[i]<<" ";}
//     cout<<endl;
//     cout<<"enter the number of word to be printed:";
//     int n;
//     cin>>n;
//     for(int j=store_nochar[n-1]+1;j<store_nochar[n];j++){
//         cout<<array1[j];
//     }
//     return 0;
// } 