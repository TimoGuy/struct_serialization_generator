## Struct definitions
```cpp

/// @HAWSOO_SERIALIZE.
struct Some_class
{
    double_t magic_number_to_save_the_world;
};

/// @HAWSOO_SERIALIZE.
struct My_class
{
    char something;
    int32_t something1;
    Some_class another_thing;
};

```

## Serializing
```cpp
My_class inst;
// Do stuff to `inst` here.

Generic_data_node gdn;
hserial::dump(inst, gdn);

gdn.write_to_file("my_dump_repr.yaml");
```

## "my_dump_repr.yaml"
```yaml
root:
  something: 'a'
  something1: -69420
  another_thing:
    magic_number_to_save_the_world: 3.1415926535
```


## Deserializing
```cpp
Generic_data_node gdn;
gdn.load_from_file("my_dump_repr.yaml");

My_class inst;
hserial::load(gdn, inst);

// Do stuff with `inst` here.
```