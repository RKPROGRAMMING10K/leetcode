int uniqueXorTriplets(int* nums, int numsSize) {
    bool has[2048]={0}, two[2048]={0}, three[2048]={0};

    if(numsSize<3){
        int ans=0;
        for(int i=0;i<numsSize;i++)
            if(!has[nums[i]]) has[nums[i]]=1,ans++;
        return ans;
    }

    for(int i=0;i<numsSize;i++) has[nums[i]]=1;

    for(int i=0;i<2048;i++)
        if(has[i])
            for(int j=0;j<2048;j++)
                if(has[j])
                    two[i^j]=1;

    for(int i=0;i<2048;i++)
        if(two[i])
            for(int j=0;j<2048;j++)
                if(has[j])
                    three[i^j]=1;

    int ans=0;
    for(int i=0;i<2048;i++) ans+=three[i];
    return ans;
}