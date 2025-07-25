a = gets.chomp
b = gets.chomp
a = a[1..-1] while a[0] == '0'
b = b[1..-1] while b[0] == '0'
puts ">" if a.length > b.length
puts "<" if a.length < b.length
exit unless a.length == b.length

(0..a.length - 1).each do |i|
  puts "<" if a[i] < b[i]
  puts ">" if a[i] > b[i]
  exit unless a[i] == b[i]
end
puts "="
