a = gets.split(' ').map(&:to_i)
ans = (a[1] + a[0] - 1) / a[0]
puts ans