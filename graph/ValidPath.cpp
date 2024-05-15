#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y, n, r;

    // Get user input for dimensions (x, y), number of circles (n), and circle radius (r)
    cout << "Enter the dimensions of the grid (x y): ";
    cin >> x >> y;

    cout << "Enter the number of circles (n): ";
    cin >> n;

    cout << "Enter the radius of the circles (r): ";
    cin >> r;

    vector<int> X, Y; // Store circle center coordinates

    // Get user input for circle center coordinates
    cout << "Enter the center coordinates (X Y) for each circle (n times):\n";
    for (int i = 0; i < n; i++) {
        int x_center, y_center;
        cin >> x_center >> y_center;
        X.push_back(x_center);
        Y.push_back(y_center);
    }

    int dx[8]={1,1,1,0,0,-1,-1,-1};
    int dy[8]={0,1,-1,1,-1,0,1,-1};

    vector<vector<bool>> mat(x+1,vector<bool>(y+1));

   // check each point is inside of any circle or not
   for(int i=0;i<=x;i++)
   for(int j=0;j<=y;j++){

       bool flag=false;
       for(int k=0;k<X.size();k++){
           if((X[k]-i)*(X[k]-i)+(Y[k]-j)*(Y[k]-j)<=r*r){
               flag=true;
               break;
           }
       }
      mat[i][j]=flag;
   }

   // if starting index is inside of any circle
   if(mat[0][0]==true){
    cout << "NO" << endl;
    return 0;
   };

    queue<pair<int,int>> q;
    q.push({0,0});
    //using the same bool matrix to make visited
    mat[0][0]=true;

    while(!q.empty()){

        pair<int,int> top=q.front();
        q.pop();

        //reach our destination
        if(top.first==x && top.second==y){
            cout << "YES" << endl;
            return 1;
        };

        //go in all 8 possible directions
        for(int i=0;i<8;i++){
            int newx=dx[i]+top.first;
            int newy=dy[i]+top.second;

            // if inside the boundary and not inside of any circle
            if(newx>=0 && newx<=x && newy>=0 && newy<=y && mat[newx][newy]==false){

               q.push({newx,newy});

               //visit the co-ordinates
               mat[newx][newy]=true;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}

