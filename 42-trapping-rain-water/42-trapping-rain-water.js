/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let totalwater = 0;
    let p1 = 0;
    let p2 = height.length - 1;
    let maxL = 0;
    let maxR = 0;
    while(p1<p2)
        {         
            if(height[p1] <= height[p2])
                {
                    if(maxL > height[p1])
                        {
                            let currentwater = maxL - height[p1];
                            totalwater = totalwater+ currentwater;
                            p1++;
                        }
                    else
                        {
                            maxL = height[p1];
                            p1++;
                        }
                }
            else
                {
                    if (maxR > height[p2])
                        {
                            let currentwater = maxR - height[p2];
                            totalwater = totalwater+ currentwater;
                            p2--;
                        }
                    else
                        {
                            maxR = height[p2];
                            p2--;
                        }
                }
        }
    return totalwater;
};