var N=1000000007
var input_data="";
//input_data_arr=new Array();
var input_data_arr=[];
function break_array(input_data) {
	input_data_arr=input_data.split('\n');
}

process.stdin.resume();
process.stdin.setEncoding("ascii");

process.stdin.on('data',function(input) {
	input_data+=input;
});

process.stdin.on('end',function () {
	//main(input_data);
	break_array(input_data);
	main();
	
})

function main() {

	var j=0;
	var t=parseInt(input_data_arr[j]);
	j++;
	var n=input_data_arr.length;
	var i=0;
	var dict={};
	for(i=0;i<=t-1;i++)
	{
		var x = parseInt(input_data_arr[j]);
		//console.log("x = "+x);
		var y=x;
		var p=0;
		var v=1;
		while(y)
		{
			if(dict[y]>0)
			{
				p+=(dict[y]*v);
				//console.log("dict["+y+"] = "+dict[y]);
				break;
			}
			p+=(y%2*v);
			y=parseInt(y/2);
			v*=10;
		}
		dict[x]=p;
		p*=2;
		var ans = (Math.pow(2,p))%N;
		console.log(ans);//((Math.pow(2,p))%N));

		j++;
	}
}