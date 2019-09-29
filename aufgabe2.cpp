#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;
int get_street_light_smaller_than_but_near_at(vector<int> ps, int point, int street_light_before){
    int nearest_latern_difference = 10000;
    int best_latern = -1;
    for(int p: ps){
        if(p <= point and p > street_light_before){
            if (abs(p - point) < nearest_latern_difference){
                best_latern = p;
                nearest_latern_difference = abs(p - point);
            }
        }
    }
    return best_latern;

}
int main() {
    int t;
    cin >> t;
    vector <int> ls(t);
    vector <int> ns(t);
    vector <int> rs(t);
    vector <vector<int>> vector_ps(t);
    for(int testcase = 0; testcase < t; testcase++){
        int l,n,r;
        cin >> l;
        cin >> n;
        cin >> r;
        vector <int> ps(n);
        for(int i = 0; i < n; i++) cin >> ps[i];

        ls[testcase] = l;
        ns[testcase] = n;
        rs[testcase] = r;
        vector_ps[testcase] = ps;
    }
    vector<string> results = vector<string>(t);
    for(int i = 0; i < t; i++){
        int l = ls[i];
        int r = rs[i];
        int n = ns[i];
        vector<int> ps = reinterpret_cast<const vector<int> &>(vector_ps[i]);

        sort(ps.begin(), ps.end()) ;

        int amount_of_street_lights_needed = 0;
        int current_street_light;

        do{
            if(amount_of_street_lights_needed == 0){
                current_street_light = get_street_light_smaller_than_but_near_at(ps, r,-1);
            }else{
                current_street_light = get_street_light_smaller_than_but_near_at(ps, current_street_light + r *2, current_street_light);
            }
            if(current_street_light == -1){
                results[i] = "impossible";
                break;
            }
            amount_of_street_lights_needed++;

        }while(current_street_light +r < l);
        if(results[i] != "impossible"){
            results[i] = std::to_string(amount_of_street_lights_needed);
        }

    }
    for(int i = 0; i < t; i++){
        cout << "Case #" << i+1 << ": " << results[i] << endl;
    }

    return 0;
}