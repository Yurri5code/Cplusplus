class Student {

public:
    void input() {
        for(int & score : scores) {
            cin >> score;;
        }
    }

    int calculateTotalScore() {
        int total = 0;
        for(int i = 0;i < 5;i++) {
            total += scores[i];
        }
        return total;
    }
private:
    int scores[5] = {0};
};

//code tres interessant 
class Student
{

private: 
    vector<int> scores; 

public: 
    void input()
    {
        int a, b, c, d, e; 
        cin >> a >> b >> c >> d >> e; 
        scores = { a, b, c, d ,e }; 
    };
    int calculateTotalScore()
    {
        return accumulate(scores.begin(), scores.end(), 0);
    }; 

};


//la fonction main
int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students

    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;

    return 0;
}
