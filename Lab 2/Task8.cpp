# include <iostream>
using namespace std;

class read_Temperature{
    float **temperatures;
    float *average;
    int days, times;

    public:
        read_Temperature(int d, int t):times(t), days(d){
            temperatures = new float*[days];
            for(int i = 0; i < days; i++){
                temperatures[i] = new float[times]();
            }
            average = new float[days];
        }

        void input_Temperature(int d, int t, float temp){
            if (d > days || t > times){
                cout << "Invalid Input!" << endl;
            }
            else{
                temperatures[d-1][t-1] = temp;
                cout << "Temperature registered" << endl;
            }
           
        }

        void daily_avg_temp(){
            cout <<"\nAverage temperatures: " << endl;
            for (int i = 0; i < days; i++){
                float total = 0;
                for(int j = 0; j < times; j++){
                    total += temperatures[i][j];
                }
                average[i] = total/times;
                cout << "Average Temperature of Day " << i+1 << ": " << total/times << " Celsius." << endl;
            }
        }

        void hottest_coldest(){
            int hottest = 0;
            int coldest = 0;
            for (int i = 0; i < days; i++){
                if(average[i] > average[hottest]){
                    hottest = i;
                }
                if(average[i] < average[coldest]){
                    coldest = i;
                }
            }
            cout << "\nHottest Day: Day " << hottest+1 << endl;
            cout << "Coldest Day: Day " << coldest+1 << endl;
        }
        
        ~read_Temperature(){
            for(int i = 0; i < days; i++){
                delete[] temperatures[i];
            }
            delete[] temperatures;
            delete[] average;
        }
};

int main(){
    read_Temperature read(3, 3);

    read.input_Temperature(1, 1, 28);
    read.input_Temperature(1, 2, 30);
    read.input_Temperature(1, 3, 24);

    read.input_Temperature(2, 1, 32);
    read.input_Temperature(2, 2, 36);
    read.input_Temperature(2, 3, 28);

    read.input_Temperature(3, 1, 36);
    read.input_Temperature(3, 2, 34);
    read.input_Temperature(3, 3, 28);
    
    read.daily_avg_temp();
    read.hottest_coldest();
}
