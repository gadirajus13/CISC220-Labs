#include <iostream>
using namespace std;
#include <unordered_map> 
#include <vector>
// Nick Fafel and Sohan Gadiraju
int main() {
 
   vector<vector<int> > wall{ { 3, 5, 1, 1 },
                              { 2, 3, 3, 2 },
                              { 5, 5 },
                              { 4, 4, 2 },
                              { 1, 3, 3, 3 },
                              { 1, 1, 6, 1, 1 } };
 
   unordered_map<int, int> cuts;
   for (int i=0; i<11; i++){
       cuts.insert({i, 0});
   }
   int currentLayerLength = 0;
 
   for (int i = 0; i < wall.size(); i++) {
       for (int j = 0; j < wall[i].size(); j++) {
           currentLayerLength += wall[i][j];
           cuts[currentLayerLength] += 1;
       }
       currentLayerLength = 0;
   }

   int indexToCut = 0;
   int maxOpenCuts = 0;

   for (int i = 1; i < 10; i++) {
       if (cuts[ i ] > maxOpenCuts) {
           maxOpenCuts = cuts[ i ];
           indexToCut = i;
       }
   }
   cout << "Index to cut through: " << indexToCut << endl;
 
   return 0;
}
