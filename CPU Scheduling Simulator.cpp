#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Defining process details
struct process
{
    string name;
    double at, bt, ct, wt, tt;
    int completed;
}
p[10];
int n;
// Sorting Processes by Arrival Time
void sortByArrival()
{
    struct process temp;
    int i, j;

    // Selection Sort applied
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {

            // Check for lesser arrival time
            if (p[i].at > p[j].at)
            {

                // Swap earlier process to front
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}


int main()
{
    int i, j, t,z,ch, sum_bt = 0;
    cout<<"Please choice your scheduling algorithms:"<<endl<<endl<<"1-For Highest response ration next "<<endl<<endl<<"2- For Shortest remaining time firs"<<endl<<"--->";
    cin>>ch;
    if(ch==1)
    {
        cout<<"Please enter the number of process"<<endl;
        cin>>n;
        int arriv[n];
        int burst[n];
        string num[n];
        float avgwt = 0, avgtt = 0;
        cout<<"Please enter the ID for each process"<<endl;
        for(int i=0; i<n; i++)
        {
            cin>>num[i];
        }
        cout<<"Please enter the Arrival time for each process"<<endl;
        for(int i=0; i<n; i++)
        {
            // predefined arrival times
            cin>>arriv[i];
        }
        cout<<"Please enter the Burst time for each process"<<endl;
        for(int i=0; i<n; i++)
        {
            // predefined burst times
            cin>>burst[i];
        }
        // Initializing the structure variables
        for (i = 0; i < n; i++)
        {
            p[i].name = num[i];
            p[i].at = arriv[i];
            p[i].bt = burst[i];

            // Variable for Completion status
            // Pending = 0
            // Completed = 1
            p[i].completed = 0;

            // Variable for sum of all Burst Times
            sum_bt += p[i].bt;
        }
        // Sorting the structure by arrival times
        sortByArrival();
        cout << "Name "  << " Arrival Time  " << "   Burst Time   "  <<  "   Waiting Time  "
             << " TurnAround Time  "<<endl;
        for (t = p[0].at; t < sum_bt;)
        {

            // Set lower limit to response ratio
            float hrr = -9999;

            // Response Ratio Variable
            float temp;

            // Variable to store next processs selected
            int loc;
            for (i = 0; i < n; i++)
            {

                // Checking if process has arrived and is Incomplete
                if (p[i].at <= t && p[i].completed != 1)
                {

                    // Calculating Response Ratio
                    temp = (p[i].bt + (t - p[i].at)) / p[i].bt;


                    // Checking for Highest Response Ratio
                    if (hrr < temp)
                    {

                        // Storing Response Ratio
                        hrr = temp;



                        // Storing Location
                        loc = i;
                    }

                }
            }
            /*
            هنا سيفت بس اول قيمة لح يبدا منها البروسس شغل عشان بعدين احسب الويتنغ للبروس من خلال طرح هاد الرقم من الارايفل تايم تبع البروسس
            */
            z=t;
            // Updating time value
            t += p[loc].bt;
            // Calculation of waiting time
            p[loc].wt = z - p[loc].at;

            // Calculation of Turn Around Time
            p[loc].tt = t - p[loc].at;

            // Sum Turn Around Time for average
            avgtt += p[loc].tt;
            // Updating Completion Status
            p[loc].completed = 1;

            // Sum Waiting Time for average
            avgwt += p[loc].wt;
            cout<< "\n" << p[loc].name <<"\t" << p[loc].at;
            cout << "\t\t" << p[loc].bt <<"\t\t"<< p[loc].wt;
            cout <<"\t\t"<<  p[loc].tt <<"\t\t"<<endl;
            for(int i=0; i<n; i++)
            {
                double x=0;
                if(p[i].at<=t&&p[i].completed!=1)
                {
                    x=((p[i].bt+(t-p[i].at))/p[i].bt);
                    cout<<"Response Time for the Process "<<p[i].name<<" is "<<x<<endl;
                }
            }
        }
        cout << "\nAverage waiting time: " << avgwt / n << endl;
        cout <<"Average Turn Around time:"<< avgtt / n;
    }
    else if(ch==2)
    {
      int a[10],b[10],x[10],temp[10];
      string id[10],temps[10];
    int waiting[10],turnaround[10];
    int i,j,smallest,count=0,time,n;
    double avg=0,tt=0,end;
    cout<<"\nEnter the number of Processes: ";  //input
    cin>>n;
    cout<<"\nEnter the ID of Processes: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>id[i];
    }
    for(i=0; i<n; i++)
    {
        cout<<"\nEnter arrival time of process "<<id[i]<<endl;  //input
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
        cout<<"\nEnter burst time of process "<<id[i]<<endl;  //input
        cin>>b[i];
    }
     for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {

            // Check for lesser arrival time
            if (a[i] > a[j])
            {

                // Swap earlier process to front
                temp[i] = b[i];
                b[i] = b[j];
                b[j] = temp[i];
                temp[i] = a[i];
                a[i] = a[j];
                a[j] = temp[i];
                temps[i] = id[i];
                id[i] = id[j];
                id[j] = temps[i];
            }
        }
    }
    for(i=0; i<n; i++)
        x[i]=b[i];
    b[9]=9999;

    for(time=0; count!=n; time++)
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
                smallest=i;
        }
        b[smallest]--;

        if(b[smallest]==0)
        {
            count++;
            end=time+1;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }
    }
    cout<<"Process"<<"\t"<< "burst-time"<<"\t"<<"arrival-time" <<"\t"<<"waiting-time" <<"\t"<<"turnaround-time"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<id[i]<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<waiting[i]<<"\t\t"<<turnaround[i]<<endl;
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    cout<<"\n\nAverage waiting time ="<<avg/n;
    cout<<"  Average Turnaround time ="<<tt/n<<endl;

    }
}
