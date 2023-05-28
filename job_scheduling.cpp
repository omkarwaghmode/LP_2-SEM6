#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vec vector
#define loop(i, n) for (int i = 0; i < n; i++)
using namespace std;
struct Job
{
	char id;
	int dead;
	int profit;
};

bool comparison(Job a, Job b)
{
	return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int &n)
{
	sort(arr, arr + n, comparison);

	int result[n];
	bool slot[n];

	for (int i = 0; i < n; i++)
	{
		slot[i] = false;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = min(n, arr[i].dead) - 1 ; j >=  0; j--)
		{
			if (slot[j] == false)
			{
				slot[j] = true;
				result[j] = i;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (slot[i])
			cout << arr[result[i]].id << " ";
}

int main()
{

	char id;
	int dead, profit;
	int n;
	cout << "total no. of jobs: " << endl;
	cin >> n;
	Job arr[n];
	for (int i = 0; i < n; i++)
	{
		cout << "For job " << i + 1 << ": " << endl;
		cout << "Enter job id: ";
		cin >> id;
		cout << "Enter job deadline: ";
		cin >> dead;
		cout << "Enter job profit: ";
		cin >> profit;
		arr[i] = {id, dead, profit};
	}

	cout << "Following is maximum profit sequence of jobs: ";
	printJobScheduling(arr, n);

	return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// struct Job {
// 	char id;
// 	int dead;
// 	int profit;
// };
// bool comparison(Job a, Job b)
// {
// 	return (a.profit > b.profit);
// }
// void printJobScheduling(Job arr[], int n)
// {
// 	sort(arr, arr + n, comparison);
// 	int result[n];
// 	bool slot[n];
// 	// Initialize all slots to be free
// 	for (int i = 0; i < n; i++)
// 		slot[i] = false;
// 	// Iterate through all given jobs
// 	for (int i = 0; i < n; i++) {
// 		cout<<"ARRRR-->>  "<<arr[i].dead<<endl;
// 		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
// 			// Free slot found
// 			if (slot[j] == false) {
// 				result[j] = i;
// 				slot[j] = true;
// 				break;
// 			}
// 		}
// 	}
// 	for (int i = 0; i < n; i++)
// 		if (slot[i])
// 			cout << arr[result[i]].id << " ";
// }
// int main()
// {
//     char id;
//     int dead,profit;
//     int n;
//     cout<<"total no. of jobs: "<<endl;
//     cin>>n;
//     Job arr[n];
//     for (int i=0;i<n;i++){
//         cout<<"For job "<<i+1<<": "<<endl;
//         cout<<"Enter job id: ";
//         cin>>id;
//         cout<<"Enter job deadline: ";
//         cin>>dead;
//         cout<<"Enter job profit: ";
//         cin>>profit;
//         arr[i]={id,dead,profit};
//     }
//     cout << "Following is maximum profit sequence of jobs: ";
// 	printJobScheduling(arr, n);
//     cout<<" \n";
// 	return 0;
// }
// /*Job arr[] = { { 'a', 2, 100 },
// 			{ 'b', 1, 19 },
// 			{ 'c', 2, 27 },
// 			{ 'd', 1, 25 },
// 			{ 'e', 3, 15 } };
// */
