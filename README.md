# string_helper

A basic string helper library in C, created as a learning exercize to get better at C.

* Create an 'instance' of the struct
``` c 
    string_helper *s = create_string_helper("Hello,");
```

* Add String as suffix 
``` c 
    string_add(s, "First ", true);
```

* Add String as prefix 
``` c 
    string_add(s, " World!", false);
```

* Replace string
``` c 
    string_replace(s, "Hello", "Greetings");
```

* Destroy the instance (free it's memory)
``` c 
    destroy_string_helper(s);
```
