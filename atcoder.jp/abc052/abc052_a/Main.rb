a = gets.split(' ').map(&:to_i)
ans = [a[0] * a[1],a[2] * a[3]].max
puts ans