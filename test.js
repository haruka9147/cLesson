// function foo1()
// {
//     return {
//         bar:"hello"
//     };
// }

// function foo2()
// {
//     return 
//     {
//         bar: "hello"
//     };
// }

// console.log(foo1());
// console.log(foo2());

function braces(values) {
    let isMatch = true;
    let str_arr = values.split('');
    for(let i = 0; i < str_arr.length; i++){
        //console.log(str_arr[i]);
        if(i % 2 == 0){
            if(str_arr[i] == '{' && str_arr[i + 1] != '}'){
                isMatch = false;
            } else if(str_arr[i] == '[' && str_arr[i + 1] != ']') {
                isMatch = false;
            } else if(str_arr[i] == '(' && str_arr[i + 1] != ')') {
                isMatch = false;
            }
        }
    }
    return isMatch;
}

console.log(braces('{}[]()'));
console.log(braces('{[}]}'));