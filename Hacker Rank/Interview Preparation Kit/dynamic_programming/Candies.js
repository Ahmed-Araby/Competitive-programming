'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');
    main();
});

function readLine() {
    return inputString[currentLine++];
}

/*
 * Complete the 'candies' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

function is_vally(arr, index)
{
    if(arr[index]<= arr[index-1] && arr[index] <= arr[index+1])
        return true;
    return false;
}

function is_rise(arr, index)
{
    if(arr[index] > arr[index-1] && arr[index]<= arr[index+1])
        return true;
    return false;
}

function is_fall(arr, index)
{
    if(arr[index] <= arr[index-1] && arr[index]>arr[index+1])
        return true;
    return false;
}

function distribute_vallys(vally, cands)
{
    let cnt = vally.length;
    for(let index of vally)
        cands[index] = 1;
    return cnt;
}
function distribute_rises(rise, cands)
{
    // left to right
    let cnt= 0;
    for(let index of rise){
        cands[index] = cands[index-1] +1; // index-1 will be vally or previous rise
        cnt += cands[index-1] +1;
    }
    return cnt;
}

function distribute_falls(falls, cands)
{
    let cnt = 0;
    // right to left
    for(let fIndex = falls.length-1; fIndex>=0; fIndex--)
    {
        let index = falls[fIndex];
        cands[index] = cands[index+1] + 1; // vally or previous fall .
        cnt += cands[index+1] + 1
    }
    return cnt;
}

function distribute_peeks(peeks, cands)
{
    let cnt = 0;
    for(let index of peeks){
        cands[index]= Math.max(cands[index-1], cands[index+1])+1;
        cnt += cands[index];
    }
    return cnt;
}

function get_arr(n)
{
    let arr = [];
    for(let index = 0; index<n; index++)
        arr.push(0);
    return arr;
}

function candies(n, arr) {
    if(n==1)
        return 1;
    
    let vally = [];
    let rise = [];
    let fall = [];
    let peek = [];
    
    // handle first element
    if(arr[0]<=arr[1]) // vally 
        vally.push(0);
    else if(arr[0]>arr[1]) // fall 
        fall.push(0);
        
    for(let index =1; index<n-1; index+=1){
        // classify elements 
        if(is_vally(arr, index))
            vally.push(index);
        else if(is_rise(arr, index))
            rise.push(index);
        else if(is_fall(arr, index))
            fall.push(index); 
        else 
            peek.push(index);
    }
    
    // handle last element
    if(arr[n-1] <= arr[n-2])
        vally.push(n-1);
    else if(arr[n-1] > arr[n-2])
        rise.push(n-1);
    
    let cands = get_arr(n);

    let ans = distribute_vallys(vally, cands);
    ans += distribute_rises(rise, cands)
    ans += distribute_falls(fall, cands);
    ans += distribute_peeks(peek, cands);
    return ans; 
}

function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const n = parseInt(readLine().trim(), 10);

    let arr = [];

    for (let i = 0; i < n; i++) {
        const arrItem = parseInt(readLine().trim(), 10);
        arr.push(arrItem);
    }

    const result = candies(n, arr);

    ws.write(result + '\n');

    ws.end();
}
