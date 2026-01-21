/* Pseudocode from class
Initialize each person and hospital to be free.
while (some hospital is free and hasn’t been matched/assigned
to every applicant) {
Choose such a hospital h
a = 1st applicant on h's list to whom h has not been
matched
if (a is free)
assign h and a
else if (a prefers h to her/his current assignment h')
assign a and h, and h’ has a slot free
else
a rejects h */
