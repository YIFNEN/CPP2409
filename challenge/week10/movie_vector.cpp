#include <iostream>
#include <vector>
using namespace std;
class Movie{
    private:
    string name;
    float score;

    public:
    Movie(){
        name = "Unknown";
        score = 0;
    }
    Movie(string title, float value){
        this-> name= title;
        this-> score = value;
    }
    void Print(){
            cout << name << ": " << score << endl; 
        }
};

int main(){
    vector<Movie> objArray;
        

    objArray.push_back(Movie("titanic", 9.9));
    objArray.push_back(Movie("gone with wind", 9.6));
    objArray.push_back(Movie("terminator", 9.7));

    for(Movie c: objArray){
            c.Print();
        }
    return 0;
}
