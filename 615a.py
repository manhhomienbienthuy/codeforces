require "set"

n, m = gets.split.map &:to_i
bulbs = Set.new
n.times do |_|
  bulbs.merge(gets.split[1..-1].map &:to_i)
end

if bulbs == (1..m).to_set
  puts "YES"
else
  puts "NO"
end
