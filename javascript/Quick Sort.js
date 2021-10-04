<html>
<head>
<title>Quick Sort in JavaScript</title>
</head>
<script type="text/javascript">
  function quick_Sorting(array) {
      if (array.length <= 1) {
      return array; // if there is only one element then return the same
} else
{
    var left = [];
    var right = [];
    var outputArray = [];
    var pivot = array.pop();
    var length = array.length;
    for (var i = 0; i < length; i++) {
    if (array[i] <= pivot) {
    left.push(array[i]);
    } else {
    right.push(array[i]);
  }
}
return outputArray.concat(quick_Sorting(left), pivot, quick_Sorting(right));
}
}
var myList = [3, 10, 2, 5, -5, 4, 7, 1];
alert("Input Array List: " + myList);
var sortedList = quick_Sorting(myList);
alert("Output Array List: " + sortedList);
</script>
<body>
</body>
</html>
