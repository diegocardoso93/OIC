const MongoClient = require('mongodb').MongoClient
const assert = require('assert')

const url = 'mongodb://localhost:27017'

const dbName = 'oic'

const mgConnect = (cb) => {
  MongoClient.connect(url, { useNewUrlParser: true }, (err, client) => {
    assert.equal(null, err)
    console.log("Connected successfully to mongo server")

    const oicDb = client.db(dbName)

    cb(oicDb, client)
  })
}

const mgFind = (db, collect, select, callback, project) => {
  const collection = db.collection(collect)
  collection.find(select, project || {}).toArray(function(err, docs) {
    assert.equal(err, null)
    console.log("Found the following records")
    console.log(docs)
    callback(docs)
  })
}

const mgInsert = (db, collect, input, callback) => {
  const collection = db.collection(collect)
  collection.insertMany(input, function(err, result) {
    assert.equal(err, null)
    console.log("Inserted "+input.length+" documents into the "+collection)
    if (callback) callback(result)
  })
}

const mgUpdate = (db, collect, where, set, callback) => {
  const collection = db.collection(collect)
  collection.updateOne(where
    , { $set: set }, function(err, result) {
    assert.equal(err, null)
    console.log("Updated the "+collection+" with "+where)
    callback(result)
  })  
}

const mgRemove = (db, collect, where, callback) => {
  const collection = db.collection(collect)
  collection.deleteOne(where, function(err, result) {
    assert.equal(err, null)
    console.log("Removed the "+collection+" with "+where)
    callback(result)
  })    
}

const mgAggregate = (db, collect, pipes, callback) => {
  const collection = db.collection(collect)
  collection.aggregate(pipes)
    .toArray((err, result) => {
      assert.equal(null, err);
      callback(result)
    })
}

module.exports = {
  mgFind: mgFind,
  mgInsert: mgInsert,
  mgUpdate: mgUpdate,
  mgRemove: mgRemove,
  mgAggregate: mgAggregate,
  mgConnect: mgConnect
}
