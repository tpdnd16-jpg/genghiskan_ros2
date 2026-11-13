import asyncio
import logging

from virtual_robot.client import BridgeClient
from virtual_robot.config import settings


def main() -> None:
    logging.basicConfig(level=logging.INFO, format="%(asctime)s %(levelname)s %(name)s: %(message)s")
    client = BridgeClient(settings)
    asyncio.run(client.run_forever())


if __name__ == "__main__":
    main()
