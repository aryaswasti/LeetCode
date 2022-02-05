/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var backspaceCompare = function(s, t) {
  let p1 = s.length-1, p2 = t.length-1, ctr1 = 0, ctr2 = 0;

  while(p1>=0 || p2>=0){
    if(s[p1] == "#" || t[p2] == "#"){
      if(s[p1] == "#"){
        ctr1++;
        p1--;
      }
      if(t[p2] == "#"){
        ctr2++;
        p2--;
      }
    } else {
      if( ctr1==0 && ctr2==0 ){
        if( s[p1] !== t[p2] ){
          return false;
        } else {
          p1--;
          p2--;
        }
      } else {
        if( ctr1 > 0 ){
          p1--;
          ctr1--;
        }
        if( ctr2 > 0 ){
          p2--;
          ctr2--;
        }
      }
    }
  }
  return true;
};