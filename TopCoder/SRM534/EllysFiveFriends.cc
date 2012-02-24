// Example 3 : 0.079 sec
// Example 4 : 0.667 sec
// Example 5 : 0.925 sec
#include <vector>
#include <map>
using namespace std;
struct Num { 
  int num[5];
  bool operator<( const Num& d ) const { 
    for( int i=0; i<5; i++ ){
      if( num[i] != d.num[i] ) return num[i] < d.num[i];
    }
    return false;
  }
};
class EllysFiveFriends{
  map<Num,int> m;
public:
  int getZero(vector <int> numbers){
    Num d;
    for( int i=0; i<5; i++ ) d.num[i] = numbers[i];
    return calc( d );
  }
  int calc( Num num ){
    int ret=0;
    int MD=1000000007;
    map<Num,int>::iterator it;
    if( num.num[0] == 0 && num.num[1] == 0 && num.num[2] == 0 && 
        num.num[3] == 0 && num.num[4] == 0 ) return 1;
    for( int i=0; i<5; i++ ){
      // apple action
      if( num.num[i] % 2 == 1 && num.num[(i+1)%5] % 2 == 1 ){
        Num d = num; d.num[i]--; d.num[(i+1)%5]--;
        it = m.find( d );
        if( it == m.end() ){ int a = calc( d ); m[d] = a; ret += a; ret %= MD; }
        else { ret += it->second; ret %= MD; }
      }
      // orange action
      if( num.num[i] > 0 && num.num[(i+1)%5] > 0 ){
        Num d = num; d.num[i]/=2; d.num[(i+1)%5]/=2;
        it = m.find( d );
        if( it == m.end() ){ int a = calc( d ); m[d] = a; ret += a; ret %= MD; }
        else { ret += it->second; ret %= MD; }
      }
    }
    return ret;
  }
};
