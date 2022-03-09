read n
func::f() {
  local -r _limit="$1"

  local _sum=1
  local i
  for i in $(seq $_limit); do
     ((_sum *= i))
  done
  echo $_sum
}
func::f $n