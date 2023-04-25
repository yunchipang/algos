# create a table T[V] = <inf, undefined>
# T[source] = <0, undefined>

# create set Q = set(V)

# while Q is not empty:
#     u = min q in Q of T[q].distance
#     S = neighbors(u)
#     Q = Q - u

#     for each neighbor v of u:
#         d = T[u].distance + E[u, v]
#         if (d < T[v].distance):
#             // it's a shorter path!
#             T[v].distance = d
#             T[v].last_step = u

# return T