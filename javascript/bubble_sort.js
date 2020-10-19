function bubbleSort(arr){
    var len = arr.length;
    for (var i = len-1; i>=0; i--){
      for(var j = 1; j<=i; j++){
        if(arr[j-1]>arr[j]){
            var temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
         }
      }
    }
    return arr;
 }
 bubbleSort([7,5,2,4,3,9]); //[2, 3, 4, 5, 7, 9]
 bubbleSort([9,7,5,4,3,1]); //[1, 3, 4, 5, 7, 9]
 bubbleSort([1,2,3,4,5,6]); //[1, 2, 3, 4, 5, 6]