#include <fstream>
#include <iostream>

#include"TaskBody.h"

using namespace std;

#define MAX_TIME 200

int main()
{
	Location location(100000000, 200000000, 10, std::list<Sprite*>());
	location.add_sprite(new TaskBody(&location, 0, 0, 0, 0, 2));

    ofstream fout("test_10.txt");
    double V;
    cout << " V = ";
    cin >> V;
    double alpha;
    cout << " alpha = ";
    cin >> alpha;
    double T;
    cout << " T = ";
    cin >> T;
    double m;
    cout << " m = ";
    cin >> m;
    double t_exp;
    cout << " t_emp = ";
    cin >> t_exp;
    bool exp = true;
    bool start = true;
    for (time_ t = 0; t < MAX_TIME; t++)
    {
        if (start && t == T) 
        {
            location.fly(V, alpha);
            start = false;
        }
        if (exp && t == t_exp) 
        {
            location.explotion(m);
            exp = false;
        }
        auto result = location.tick(1);
        fout << t<<": ";
        for (auto _body : result)
            fout << _body<<"\t";
        fout << endl;

        location.stay();
    }
	return 0;
}