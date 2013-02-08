slog-ng-3.1.2-logsigner
=========================

Syslog-ng-3.1.2 log signing mechanism for syslog-ng version 3.1.2 stamping the log entries of syslog-ng log files
in a hash chain logic by utilizing Message Authentication Codes. This method provides a way of performing integrity
checks on log files suitable for forensic investigations.

In the src/ folder there is the source code implementation of syslog-ng-3.1.2 with any additional files imlementing
the patch and any modifications to the original files.

The new files are:
logsigner.c
logsinger.h

Modifies files are:
main.c
logtransport.c
logtransport.h
cfg.c
cfg.h
affile.c
affile.h
cfg-grammar.y
cfg-lex.l
logwriter.c
logwriter.h
Makefile

Notice: In the implementation there has been used some external libraries implementing hash and mac functions.
These are:
md5.c
md5.h
sha1.c
sha1.h
hmac-md5.c
hmac-md5.h
hmac-sha1.c
hmac-sha1.h
memxor.c
memxor.h
error\_handling.c
For details look on the top comments.
