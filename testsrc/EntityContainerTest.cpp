// #include "../src/EntityContainer.h"
// #include "../src/CollisionDetector.h"
// #include "../src/DeltatimeMonitor.h"
// #include "../src/EntityProperties.h"
// #include "../src/GameData.h"
// #include "../src/MapArea.h"
// #include "../src/Mixer.h"
// #include "EntityImpl.h"
// #include "catch.hpp"

// TEST_CASE("Object container tests", "[objectcontainer]")
// {
// 	flat2d::DeltatimeMonitor* dtm = new flat2d::DeltatimeMonitor();
// 	flat2d::EntityContainer container(dtm);

// 	SECTION("Test container destructor", "[objectcontainer]")
// 	{
// 		flat2d::Entity* c = new EntityImpl(100, 100);

// 		REQUIRE(0 == container.getObjectCount());
// 		container.registerObject(c);
// 		REQUIRE(1 == container.getObjectCount());
// 		container.registerObject(c);
// 		REQUIRE(1 == container.getObjectCount());
// 		container.unregisterObject(c);
// 		REQUIRE(0 == container.getObjectCount());

// 		// 		delete c;
// 		// 	}

// 		SECTION("Test container destructor", "[objectcontainer]")
// 		{
// 			flat2d::Entity* c = new EntityImpl(100, 100);

// 			REQUIRE(0 == container.getObjectCount());

// 			// 		REQUIRE( 1 == container.getObjectCount() );

// 			REQUIRE(1 == container.getObjectCount());

// 			// 		REQUIRE( 1 == container.getObjectCount() );
// 			// 	}

// 			REQUIRE(1 == container.getObjectCount());
// 		}

// 		SECTION("Test unregister", "[objectcontainer]")
// 		{
// 			flat2d::Entity* c = new EntityImpl(100, 100);

// 			// 		delete c;
// 			// 	}

// 			// 	SECTION( "Test layers", "[objectcontainer]" )
// 			// 	{
// 			// 		flat2d::Entity* c1 = new EntityImpl(100, 100);
// 			// 		flat2d::Entity* c2 = new EntityImpl(100, 100);
// 			// 		flat2d::Entity* c3 = new EntityImpl(100, 100);

// 			SECTION("Test layers", "[objectcontainer]")
// 			{
// 				flat2d::Entity* c1 = new EntityImpl(100, 100);
// 				flat2d::Entity* c2 = new EntityImpl(100, 100);
// 				flat2d::Entity* c3 = new EntityImpl(100, 100);

// 				REQUIRE(0 == container.getObjectCountFor(0));

// 				// 		container.registerObject(c1);

// 				// 		REQUIRE( 1 == container.getObjectCount() );
// 				// 		REQUIRE( 1 ==
// 				// container.getObjectCountFor(flat2d::EntityContainer::DEFAULT_LAYER)
// 				// );

// 				REQUIRE(1 == container.getObjectCount());
// 				REQUIRE(1 == container.getObjectCountFor(
// 				               flat2d::EntityContainer::DEFAULT_LAYER));

// 				// 		REQUIRE( 2 == container.getObjectCount() );
// 				// 		REQUIRE( 1 == container.getObjectCountFor(0) );
// 				// 		REQUIRE( 0 == container.getObjectCountFor(1) );

// 				REQUIRE(2 == container.getObjectCount());
// 				REQUIRE(1 == container.getObjectCountFor(0));
// 				REQUIRE(0 == container.getObjectCountFor(1));

// 				// 		REQUIRE( 1 == container.getObjectCountFor(1) );
// 				// 		REQUIRE( 3 == container.getObjectCount() );

// 				REQUIRE(1 == container.getObjectCountFor(1));
// 				REQUIRE(3 == container.getObjectCount());

// 				// 		REQUIRE( 0 == container.getObjectCountFor(0) );
// 				// 		REQUIRE( 2 == container.getObjectCount() );

// 				REQUIRE(0 == container.getObjectCountFor(0));
// 				REQUIRE(2 == container.getObjectCount());

// 				// 	SECTION( "Test clearing layers", "[objectcontainer]" )
// 				// 	{
// 				// 		flat2d::Entity* c1 = new EntityImpl(100, 100);
// 				// 		flat2d::Entity* c2 = new EntityImpl(100, 100);
// 				// 		flat2d::Entity* c3 = new EntityImpl(100, 100);
// 				// 		flat2d::Entity* c4 = new EntityImpl(100, 100);
// 				// 		flat2d::Entity* c5 = new EntityImpl(100, 100);
// 				// 		flat2d::Entity* c6 = new EntityImpl(100, 100);

// 				SECTION("Test clearing layers", "[objectcontainer]")
// 				{
// 					flat2d::Entity* c1 = new EntityImpl(100, 100);
// 					flat2d::Entity* c2 = new EntityImpl(100, 100);
// 					flat2d::Entity* c3 = new EntityImpl(100, 100);
// 					flat2d::Entity* c4 = new EntityImpl(100, 100);
// 					flat2d::Entity* c5 = new EntityImpl(100, 100);
// 					flat2d::Entity* c6 = new EntityImpl(100, 100);

// 					// 		container.addLayer(backLayer);
// 					// 		container.addLayer(frontLayer);

// 					// 		container.registerObject(c1, frontLayer);
// 					// 		container.registerObject(c2, frontLayer);
// 					// 		container.registerObject(c3, frontLayer);
// 					// 		container.registerObject(c4, backLayer);
// 					// 		container.registerObject(c5, backLayer);
// 					// 		container.registerObject(c6, backLayer);

// 					// 		REQUIRE ( 6 == container.getObjectCount() );
// 					// 		REQUIRE ( 3 == container.getObjectCountFor(frontLayer)
// 					// ); 		REQUIRE ( 3 == container.getObjectCountFor(backLayer)
// 					// );

// 					REQUIRE(6 == container.getObjectCount());
// 					REQUIRE(3 == container.getObjectCountFor(frontLayer));
// 					REQUIRE(3 == container.getObjectCountFor(backLayer));

// 					// 		REQUIRE ( 3 == container.getObjectCount() );
// 					// 		REQUIRE ( 0 == container.getObjectCountFor(frontLayer)
// 					// ); 		REQUIRE ( 3 == container.getObjectCountFor(backLayer)
// 					// );
// 					// 	}

// 					REQUIRE(3 == container.getObjectCount());
// 					REQUIRE(0 == container.getObjectCountFor(frontLayer));
// 					REQUIRE(3 == container.getObjectCountFor(backLayer));
// 				}

// 				SECTION("Test auto cleaning", "[objectcontainer]")
// 				{
// 					flat2d::Entity* c1 = new EntityImpl(100, 100);
// 					EntityImpl* c2 = new EntityImpl(100, 100);

// 					flat2d::CollisionDetector detector(&container, dtm);
// 					flat2d::Mixer mixer;
// 					flat2d::GameData gameData(
// 					  &container,
// 					  &detector,
// 					  &mixer,
// 					  (flat2d::RenderData*)nullptr,
// 					  (flat2d::DeltatimeMonitor*)nullptr);

// 					// 		REQUIRE ( 2 == container.getObjectCount() );

// 					REQUIRE(2 == container.getObjectCount());

// 					// 		REQUIRE ( 1 == container.getObjectCount() );
// 					// 	}

// 					REQUIRE(1 == container.getObjectCount());
// 				}

// 				SECTION("Test partition handling", "[objectcontainer]")
// 				{
// 					flat2d::CollisionDetector detector(&container, dtm);
// 					flat2d::GameData gameData(
// 					  &container,
// 					  &detector,
// 					  nullptr,
// 					  (flat2d::RenderData*)nullptr,
// 					  (flat2d::DeltatimeMonitor*)nullptr);

// 					// 		container.setSpatialPartitionDimension(100);
// 					// 		container.registerObject(o);
// 					// 		container.initiateEntities(&gameData);

// 					// 		REQUIRE( 4 ==
// 					// o->getEntityProperties().getCurrentAreas().size() );

// 					REQUIRE(4 ==
// 					        o->getEntityProperties().getCurrentAreas().size());

// 					// 		REQUIRE( 2 ==
// 					// o->getEntityProperties().getCurrentAreas().size() );
// 					// 	}

// 					REQUIRE(2 ==
// 					        o->getEntityProperties().getCurrentAreas().size());
// 				}

// 				SECTION("Test spatial partitions", "[objectcontainer]")
// 				{

// 					// 		container.registerObject(o1);
// 					// 		REQUIRE ( 1 == container.getSpatialPartitionCount()
// 					// );

// 					container.registerObject(o1);
// 					REQUIRE(1 == container.getSpatialPartitionCount());

// 					container.registerObject(o4);
// 					REQUIRE(1 == container.getSpatialPartitionCount());

// 					container.registerObject(o2);
// 					REQUIRE(2 == container.getSpatialPartitionCount());

// 					container.registerObject(o3);
// 					REQUIRE(3 == container.getSpatialPartitionCount());

// 					container.registerObject(o5);
// 					REQUIRE(7 == container.getSpatialPartitionCount());
// 				}

// 				SECTION("Test spatial partitions with velocity",
// 				        "[objectcontainer]")
// 				{

// 					// 		flat2d::EntityProperties& o1props =
// 					// o1->getEntityProperties(); 		o1props.setXvel(50);
// 					// 		o1props.setYvel(50);

// 					// 		flat2d::EntityProperties& o2props =
// 					// o2->getEntityProperties(); 		o2props.setXvel(-50);
// 					// 		o2props.setYvel(-50);

// 					// 		REQUIRE ( 1.0 == dtm->getDeltaTime() );

// 					REQUIRE(1.0 == dtm->getDeltaTime());

// 					REQUIRE(0 == container.getSpatialPartitionCount());

// 					// 		REQUIRE ( 4 == container.getSpatialPartitionCount()
// 					// );

// 					REQUIRE(4 == container.getSpatialPartitionCount());

// 					// 		REQUIRE ( 0 == container.getSpatialPartitionCount()
// 					// );

// 					REQUIRE(0 == container.getSpatialPartitionCount());

// 					// 		REQUIRE ( 4 == container.getSpatialPartitionCount()
// 					// );
// 					// 	}

// 					REQUIRE(4 == container.getSpatialPartitionCount());
// 				}

// 				delete dtm;
// 			}
