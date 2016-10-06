/*
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :

A : [3 5 4 2]

Output : 2 
for the pair (3, 4)
*/

int Solution::maximumGap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<pair<int,int> > m;
    
    vector< pair < int ,int > >::iterator it1,it2,it;
    int i,j,k,l,n,maxr,minl;
    n=A.size();
    vector <int> lmin(n),rmax(n);
    if(n==1)
        return 0;
    for(i=0;i<n;i++){
        m.push_back(make_pair(A[i],i));
    }
    sort(m.begin(),m.end());
    
    /*
    for(it1=m.begin();it1!=m.end();++it1)
    {
        for(it2= it1+1;it2!=m.end();++it2)
        {
            if((it2->second - it1->second)>max){
                max = it2->second - it1->second;
            }
        }
    }*/
    it1 = m.begin();
    it2 = m.end()-1;
    lmin[0] = it1->second;
    //rmax.push_back(it2->second);
    rmax[n-1] = it2->second;
    minl = it1->second;
    maxr = it2->second;
    
    //cout<<(m.begin())<<" "<<m.end();
    i=1;
    for( it = m.begin()+1; it!=m.end() ; ++it)
    {
        lmin[i] = (min(it->second, minl));
        i++;
    }
    j=n-2;
    for( it = m.end()-2; it>=m.begin() ; --it)
    {
        rmax[j] = (min(it->second, maxr));
        j--;
    }
    for(i=0;i<n;i++)
    {
        //cout<<lmin[i]<<" ";
    }
    //cout<<"cc "<<n<<" ";
    for(i=0;i<n;i++)
    {
        //cout<<rmax[i]<<" ";
    }
    i=0;j=0;k=-1;
    while(i < n && j<n)
    {
        if(lmin[i]<rmax[j])
        {
            k = max(k,j-i);
            j++;
        }
        else{
            
            i++;
        }
            
    }
    return k;

}
