#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct meet
{
    int start;
    int end;
    int pos;
};


bool comparator(struct meet m1, struct meet m2)
{
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.pos < m2.pos) return true;
    return false;
}


vector<int> maximumMeetings(vector<int> &start, vector<int> &end) 
{
    int n = start.size();

    //create an array of struct meet
    struct meet meetings[n];

    //push the elements into meetings array
    for(int i=0; i<n; i++)
    {
        meetings[i].start = start[i], meetings[i].end = end[i], meetings[i].pos = i+1;
    }

    //sort the array of [[start, end, pos],....] on the basis of end time of meeting
    sort(meetings, meetings+n, comparator);

    vector<int> output;
    output.push_back(meetings[0].pos);  //push the first meet pos, as it is sure to occur first meet

    int lastMeet = meetings[0].end;  //keep track of the last meet end time

    for(int i=1; i<n; i++)
    {
        if(meetings[i].start > lastMeet)  // if the start time of current meet is greater than last meet end time
        {
            output.push_back(meetings[i].pos);  //then store the pos of the current meet
            lastMeet = meetings[i].end; // update the last meet value to current meet end time
        }
    }
    return output; //return the output array
}

int main()
{
    //let's run our code 
    int n, val;
    cin>>n;
    vector<int> start, end, output;
    for(int i=0; i<n; i++)
    {   
        cin>>val;
        start.push_back(val);
    }
    for(int i=0; i<n; i++)
    {   
        cin>>val;
        end.push_back(val);
    }
    output = maximumMeetings(start, end);
    for(int i=0; i<output.size(); i++)
    {
        cout<<output[i]<<" ";
    }
    cout<<endl;
}