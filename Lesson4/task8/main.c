#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

int main() {
    uid_t uid = getuid();
    gid_t gid = getgid();

    struct passwd *pw;

    printf("User is %s\n", getlogin());

    printf("User IDs: uid = %d, gid = %d\n", uid, gid);

    pw = getpwuid(uid);
    printf("UID passwd entry:\n");
    printf("Name = %s, UserID = %d, GroupID = %d, Home = %s, Shell = %s\n", pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir, pw->pw_shell);

    pw = getpwnam("root");
    printf("Root passwd entry:\n");
    printf("Name = %s, UserID = %d, GroupID = %d, Home = %s, Shell = %s\n\n", pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir, pw->pw_shell);

    return 0;
}
