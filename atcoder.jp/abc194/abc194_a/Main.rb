a = gets.split(' ').map(&:to_i)
res = 4
if a[0]+a[1] >= 15 && a[1] >= 8
    res = 1
elsif a[0]+a[1] >= 10 && a[1] >= 3
    res = 2
elsif a[0]+a[1] >= 3
    res = 3
end
puts res
