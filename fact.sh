factorial()
{
    product=$1
    if((product<=2)) 
    then
      echo $product
    else
     f=$((product-1))
     f=$(factorial $f)
     f=$((f*product))
     echo $f
     fi

}
read num
factorial $num
