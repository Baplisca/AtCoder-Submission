a = gets.split(' ').map(&:to_i)
res = (a[0] < a[1])?"Better":"Worse"
puts res
