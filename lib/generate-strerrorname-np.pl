#!/usr/bin/env perl

# Make sure that an error is only printed once.
my %seen_errrors;

# This is a new-line separated list of error numbers that may contain repeats.
# If an error may share the same numerical representation as another add a
# check for use with the C preprocessor.
my $error_number_list = "
/* Error numbers required by C99. */
EDOM
EILSEQ
ERANGE

/* Error numbers required by POSIX.1-2017. */
E2BIG
EACCES
EADDRINUSE
EADDRNOTAVAIL
EAFNOSUPPORT
EAGAIN
EALREADY
EBADF
EBADMSG
EBUSY
ECANCELED
ECHILD
ECONNABORTED
ECONNREFUSED
ECONNRESET
EDEADLK
EDESTADDRREQ
EDOM
EDQUOT
EEXIST
EFAULT
EFBIG
EHOSTUNREACH
EIDRM
EILSEQ
EINPROGRESS
EINTR
EINVAL
EIO
EISCONN
EISDIR
ELOOP
EMFILE
EMLINK
EMSGSIZE
EMULTIHOP
ENAMETOOLONG
ENETDOWN
ENETRESET
ENETUNREACH
ENFILE
ENOBUFS
ENODATA
ENODEV
ENOENT
ENOEXEC
ENOLCK
ENOLINK
ENOMEM
ENOMSG
ENOPROTOOPT
ENOSPC
ENOSR
ENOSTR
ENOSYS
ENOTCONN
ENOTDIR
ENOTEMPTY
ENOTRECOVERABLE
ENOTSOCK
/* May be the same value as EOPNOTSUPP. */
ENOTSUP && ENOTSUP != EOPNOTSUPP
ENOTTY
ENXIO
EOPNOTSUPP
EOVERFLOW
EOWNERDEAD
EPERM
EPIPE
EPROTO
EPROTONOSUPPORT
EPROTOTYPE
ERANGE
EROFS
ESPIPE
ESRCH
ESTALE
ETIME
ETIMEDOUT
ETXTBSY
/* May be the same value as EAGAIN. */
EWOULDBLOCK && EWOULDBLOCK != EAGAIN
EXDEV
";

print <<EOF

const char *
strerrorname_np (int errnum)
{
  switch (errnum)
    {
EOF
  ;
foreach (split (/\n/, $error_number_list))
  {
    if ($_ =~ /\/\*/)
      {
        print ("$_\n");
      }
    elsif ($_ =~ /\s*(E\w+)(?:([^\n]*))?/)
      {
        my $error = $1;
        my $extra = defined ($2) ? $2 : "";
        if (!exists ($seen_errors{$error}))
          {
            print <<EOF
#if defined($error)$extra
    case $error:
      return \"$error\";
#endif
EOF
              ;
            $seen_errors{$error} = 1;
          }
      }
  }
print <<EOF
    default:
      return NULL;
    }
  return NULL;
}
EOF
  ;
