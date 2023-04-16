//implementation of shell sort based on the short bit of psuedocode from class

include "Shell.cpp"

static void Shell::Sort(vector<County*>& counties, string toSortBy){
    for(int gap = counties.size() / 2; gap > 0; gap /= 2.2){ //gap starts at half the vector size, and is divided by 2.2 each iteration according to class notes
        for(int i = gap; i < counties.size(); i++){
            int cur = i; //we will follow vector[cur], which will start being at i but will often decrease, but we don't want to modify i here
            if(cur - gap >= 0 && GetStatistic(counties.at(cur), toSortBy) < GetStatistic(counties.at(cur - gap), toSortBy)){  //check if our current value is less than the value we get from going back 'gap' amount in the vector
                //we need to swap
                County* temp = counties.at(cur - gap);
                counfsdfsfs
            }
        }
        if(gap = 2){
            gap = 3;    // 3/2.2 = 1, which is what we want
        }
    }

}

static float Shell::GetStatistic(County* county, string statisticName){

}