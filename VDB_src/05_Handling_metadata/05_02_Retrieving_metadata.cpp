#include <openvdb/openvdb.h>

int main()
{
    openvdb::initialize();

    openvdb::Vec3SGrid::Ptr grid = openvdb::Vec3SGrid::create();

    grid->insertMeta("vector type", openvdb::StringMetadata("covariant (gradient)"));
    grid->insertMeta("radius", openvdb::FloatMetadata(50.0));
    grid->insertMeta("center", openvdb::Vec3SMetadata(openvdb::Vec3s(10, 15, 10)));

    // OK, overwrites existing value:
    grid->insertMeta("center", openvdb::Vec3SMetadata(openvdb::Vec3s(10.5, 15, 30)));

    // Error (throws openvdb::TypeError), can't overwrite a value of type Vec3S
    // with a value of type float:
    // grid->insertMeta("center", openvdb::FloatMetadata(0.0));

    std::string s = grid->metaValue<std::string>("vector type");

    float r = grid->metaValue<float>("radius");

    // Error (throws openvdb::TypeError), can't read a value of type Vec3S as a float:
    // float center = grid->metaValue<float>("center");

    for (openvdb::MetaMap::MetaIterator iter = grid->beginMeta();
         iter != grid->endMeta(); ++iter)
    {
        const std::string &name = iter->first;
        openvdb::Metadata::Ptr value = iter->second;
        std::string valueAsString = value->str();
        std::cout << name << " = " << valueAsString << std::endl;
    }

    openvdb::Metadata::Ptr metadata = grid->operator[]("center");

    // See typenameAsString<T>() in Types.h for a list of strings that can be
    // returned by the typeName() method.
    std::cout << metadata->typeName() << std::endl; // prints "vec3s"

    // One way to process metadata of arbitrary types:
    if (metadata->typeName() == openvdb::StringMetadata::staticTypeName())
    {
        std::string s = static_cast<openvdb::StringMetadata &>(*metadata).value();
    }
    else if (metadata->typeName() == openvdb::FloatMetadata::staticTypeName())
    {
        float f = static_cast<openvdb::FloatMetadata &>(*metadata).value();
    }
    else if (metadata->typeName() == openvdb::Vec3SMetadata::staticTypeName())
    {
        openvdb::Vec3s v = static_cast<openvdb::Vec3SMetadata &>(*metadata).value();
    }
}