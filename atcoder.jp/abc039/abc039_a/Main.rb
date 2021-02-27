d = gets.split(' ').map(&:to_i)
area = d[0] * d[1] + d[1] * d[2] + d[2] * d[0]
puts area * 2